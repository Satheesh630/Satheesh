#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/delay.h>

#define VENDOR_ID       0x8564
#define PRODUCT_ID      0x4000

#define CBW_SIGNATURE   0x43425355
#define CSW_SIGNATURE   0x53425355

#define SECTOR_SIZE     block_size

#define SCSI_INQUIRY        0x12
#define SCSI_TEST_UNIT_READY 0x00
#define SCSI_REQUEST_SENSE  0x03
#define SCSI_READ_CAPACITY  0x25
#define SCSI_READ10         0x28

#define INQUIRY_LENGTH      36
#define SENSE_LENGTH        18

u32 block_size = 0;

struct my_cbw {
	__le32 signature;
	__le32 tag;
	__le32 data_transfer_length;
	u8 flags;
	u8 lun;
	u8 cb_length;
	u8 cb[16];
} __packed;


struct my_csw {
	__le32 signature;
	__le32 tag;
	__le32 residue;
	u8 status;
} __packed;


struct my_device {
	struct usb_device *udev;
	struct usb_interface *interface;

	u8 bulk_in;
	u8 bulk_out;
	
};



/*
 * SCSI INQUIRY
*/
static int inquiry(struct my_device *dev)
{
	struct my_cbw *cbw;
	struct my_csw *csw;
	u8 *buffer;

	int actual;
	int ret;

	u32 tag = 0x10000001;

	cbw = kzalloc(sizeof(*cbw), GFP_KERNEL);
	if (!cbw)
		return -ENOMEM;

	csw = kzalloc(sizeof(*csw), GFP_KERNEL);
	if (!csw) {
		kfree(cbw);
		return -ENOMEM;
	}

	buffer = kzalloc(INQUIRY_LENGTH, GFP_KERNEL);
	if (!buffer) {
		kfree(csw);
		kfree(cbw);
		return -ENOMEM;
	}

	/*
	 * Build CBW
	 */

	cbw->signature = cpu_to_le32(CBW_SIGNATURE);
	//cbw->signature = CBW_SIGNATURE;

	cbw->tag = cpu_to_le32(tag);

	cbw->data_transfer_length =
		cpu_to_le32(INQUIRY_LENGTH);

	cbw->flags = 0x80;	/* Device -> Host */
	cbw->lun = 0;
	cbw->cb_length = 6;

	cbw->cb[0] = SCSI_INQUIRY;//opcode of command   
	cbw->cb[1] = 0x00;	//EVPD
	cbw->cb[2] = 0x00;	//page code
	cbw->cb[3] = 0x00;	//Reserved
	cbw->cb[4] = INQUIRY_LENGTH;	//Allocation length
	cbw->cb[5] = 0x00;	//control


	pr_info("sd_reader: SCSI INQUIRY command sent\n");


	/*
	 * Send CBW
	 */

	ret = usb_bulk_msg(dev->udev,usb_sndbulkpipe(dev->udev, dev->bulk_out),cbw,sizeof(*cbw),&actual,5000);

	if (ret) {
		pr_err("sd_reader: INQUIRY CBW failed: %d\n", ret);
		goto out;
	}

	if (actual != sizeof(*cbw)) {
		pr_err("sd_reader: INQUIRY CBW size error: %d\n",actual);
		ret = -EIO;
		goto out;
	}


	/*
	 * Receive INQUIRY data
	 */

	ret = usb_bulk_msg(dev->udev,usb_rcvbulkpipe(dev->udev, dev->bulk_in),buffer,INQUIRY_LENGTH,&actual,5000);

	if (ret) {
		pr_err("sd_reader: INQUIRY data failed: %d\n", ret);
		goto out;
	}

	pr_info("sd_reader: INQUIRY received %d bytes\n", actual);

	if (actual != INQUIRY_LENGTH) {
		pr_err("sd_reader: INQUIRY size error: %d\n",actual);
		ret = -EIO;
		goto out;
	}


	print_hex_dump(KERN_INFO,"sd_reader: INQUIRY: ",DUMP_PREFIX_OFFSET,16,1,buffer,INQUIRY_LENGTH,true);

	pr_info("sd_reader: Vendor  : %.8s\n", &buffer[8]);
	pr_info("sd_reader: Product : %.16s\n", &buffer[16]);
	pr_info("sd_reader: Revision: %.4s\n", &buffer[32]);
	/*
	 * Receive CSW
	 */

	ret = usb_bulk_msg(dev->udev,usb_rcvbulkpipe(dev->udev, dev->bulk_in),csw,sizeof(*csw),&actual,5000);

	if (ret) {
		pr_err("sd_reader: INQUIRY CSW failed: %d\n", ret);
		goto out;
	}

	pr_info("sd_reader: INQUIRY CSW received %d bytes\n",
			actual);

	if (actual != sizeof(*csw)) {
		pr_err("sd_reader: INQUIRY CSW size error: %d\n",
				actual);
		ret = -EIO;
		goto out;
	}


	if (le32_to_cpu(csw->signature) != CSW_SIGNATURE) {
		pr_err("sd_reader: Invalid INQUIRY CSW signature\n");
		ret = -EIO;
		goto out;
	}


	if (le32_to_cpu(csw->tag) != tag) {
		pr_err("sd_reader: INQUIRY CSW tag mismatch\n");
		ret = -EIO;
		goto out;
	}


	pr_info("sd_reader: INQUIRY residue = %u\n",
			le32_to_cpu(csw->residue));

	pr_info("sd_reader: INQUIRY status = 0x%02x\n",
			csw->status);


	if (csw->status != 0) {
		pr_err("sd_reader: INQUIRY command failed\n");
		ret = -EIO;
		goto out;
	}


	pr_info("sd_reader: INQUIRY successful\n");

	ret = 0;

out:

	kfree(buffer);
	kfree(csw);
	kfree(cbw);

	return ret;
}

/*
 * ---------------------------------------------------------
 * REQUEST SENSE
 * ---------------------------------------------------------
 */

static int request_sense(struct my_device *dev)
{
	struct my_cbw *cbw;
	struct my_csw *csw;
	u8 *buffer;

	int actual;
	int ret;

	u32 tag = 0x10000002;

	cbw = kzalloc(sizeof(*cbw), GFP_KERNEL);
	if (!cbw)
		return -ENOMEM;

	csw = kzalloc(sizeof(*csw), GFP_KERNEL);
	if (!csw) {
		kfree(cbw);
		return -ENOMEM;
	}

	buffer = kzalloc(SENSE_LENGTH, GFP_KERNEL);
	if (!buffer) {
		kfree(csw);
		kfree(cbw);
		return -ENOMEM;
	}

	/*
	 * Build REQUEST SENSE CBW
	 */

	cbw->signature = cpu_to_le32(CBW_SIGNATURE);
	cbw->tag = cpu_to_le32(tag);

	cbw->data_transfer_length =
		cpu_to_le32(SENSE_LENGTH);

	cbw->flags = 0x80;
	cbw->lun = 0;
	// Bytes ofx cbw to consider remaining are reserved
	cbw->cb_length = 6;

	cbw->cb[0] = SCSI_REQUEST_SENSE;
	cbw->cb[1] = 0x00;
	cbw->cb[2] = 0x00;
	cbw->cb[3] = 0x00;
	cbw->cb[4] = SENSE_LENGTH; // Return sense data length
	cbw->cb[5] = 0x00;


	pr_info("sd_reader: SCSI REQUEST SENSE command sent\n");
	/*
	 * Send CBW
	 */
	ret = usb_bulk_msg(dev->udev,usb_sndbulkpipe(dev->udev, dev->bulk_out),cbw,sizeof(*cbw),&actual,5000);
	if (ret) {
		pr_err("sd_reader: REQUEST SENSE CBW failed: %d\n",
				ret);
		goto out;
	}
	if (actual != sizeof(*cbw)) {
		pr_err("sd_reader: REQUEST SENSE CBW size error\n");
		ret = -EIO;
		goto out;
	}

	/*
	 * Receive sense data
	 */

	ret = usb_bulk_msg(dev->udev,usb_rcvbulkpipe(dev->udev, dev->bulk_in),buffer,SENSE_LENGTH,&actual,5000);

	if (ret) {
		pr_err("sd_reader: REQUEST SENSE data failed: %d\n",ret);
		goto out;
	}


	pr_info("sd_reader: REQUEST SENSE received %d bytes\n",actual);

	print_hex_dump(KERN_INFO,"sd_reader: Sense: ",DUMP_PREFIX_OFFSET,16,1,buffer,actual,true);


	if (actual >= 14) {

		pr_info("sd_reader: Sense Key = 0x%02x\n",buffer[2] & 0x0f);

		pr_info("sd_reader: ASC = 0x%02x\n",buffer[12]);

		pr_info("sd_reader: ASCQ = 0x%02x\n",buffer[13]);

		if ((buffer[2] & 0x0f) == 0x06 &&
				buffer[12] == 0x28) {

			pr_info("sd_reader: Media change detected\n");
		}

		if ((buffer[2] & 0x0f) == 0x02 &&
				buffer[12] == 0x3a) {

			pr_info("sd_reader: No medium present\n");
		}
	}


	/*
	 * Receive CSW
	 */

	ret = usb_bulk_msg(dev->udev,usb_rcvbulkpipe(dev->udev, dev->bulk_in),csw,sizeof(*csw),&actual,5000);

	if (ret) {
		pr_err("sd_reader: REQUEST SENSE CSW failed: %d\n",
				ret);
		goto out;
	}


	pr_info("sd_reader: REQUEST SENSE status = 0x%02x\n",
			csw->status);

	if (actual != sizeof(*csw)) {
		pr_err("sd_reader: REQUEST SENSE CSW size error\n");
		ret = -EIO;
		goto out;
	}


	if (le32_to_cpu(csw->signature) != CSW_SIGNATURE) {
		pr_err("sd_reader: Invalid REQUEST SENSE CSW\n");
		ret = -EIO;
		goto out;
	}


	if (le32_to_cpu(csw->tag) != tag) {
		pr_err("sd_reader: REQUEST SENSE tag mismatch\n");
		ret = -EIO;
		goto out;
	}


	if (csw->status != 0) {
		pr_err("sd_reader: REQUEST SENSE command failed\n");
		ret = -EIO;
		goto out;
	}


	pr_info("sd_reader: REQUEST SENSE successful\n");

	ret = 0;

out:

	kfree(buffer);
	kfree(csw);
	kfree(cbw);

	return ret;
}


/*
 * ---------------------------------------------------------
 * TEST UNIT READY
 * ---------------------------------------------------------
 */

static int test_unit_ready(struct my_device *dev)
{
	struct my_cbw *cbw;
	struct my_csw *csw;

	int actual;
	int ret;

	u32 tag = 0x10000003;


	cbw = kzalloc(sizeof(*cbw), GFP_KERNEL);
	if (!cbw)
		return -ENOMEM;

	csw = kzalloc(sizeof(*csw), GFP_KERNEL);
	if (!csw) {
		kfree(cbw);
		return -ENOMEM;
	}


	/*
	 * Build TEST UNIT READY CBW
	 */
	// Command 0x00
	cbw->signature = cpu_to_le32(CBW_SIGNATURE);
	cbw->tag = cpu_to_le32(tag);

	cbw->data_transfer_length = cpu_to_le32(0);

	cbw->flags = 0x00; // device to host

	cbw->lun = 0;

	cbw->cb_length = 6;

	cbw->cb[0] = SCSI_TEST_UNIT_READY;


	pr_info("sd_reader: SCSI TEST UNIT READY command sent\n");


	/*
	 * Send CBW
	 */

	ret = usb_bulk_msg(dev->udev,usb_sndbulkpipe(dev->udev, dev->bulk_out),cbw,sizeof(*cbw),&actual,5000);

	if (ret) {
		pr_err("sd_reader: TEST UNIT READY CBW failed: %d\n",
				ret);
		goto out;
	}

	if (actual != sizeof(*cbw)) {
		pr_err("sd_reader: TEST UNIT READY CBW size error: %d\n",
				actual);
		ret = -EIO;
		goto out;
	}

	pr_info("sd_reader: TEST UNIT READY CBW sent\n");


	/*
	 * TEST UNIT READY has NO DATA phase.
	 *
	 * Receive CSW directly.
	 */

	ret = usb_bulk_msg(dev->udev,usb_rcvbulkpipe(dev->udev, dev->bulk_in),csw,sizeof(*csw),&actual,5000);

	if (ret) {
		pr_err("sd_reader: TEST UNIT READY CSW failed: %d\n",
				ret);
		goto out;
	}


	pr_info("sd_reader: TEST UNIT READY CSW received %d bytes\n",actual);


	if (actual != sizeof(*csw)) {
		pr_err("sd_reader: TEST UNIT READY CSW size error: %d\n",actual);
		ret = -EIO;
		goto out;
	}


	if (le32_to_cpu(csw->signature) != CSW_SIGNATURE) {
		pr_err("sd_reader: Invalid TEST UNIT READY CSW signature\n");
		ret = -EIO;
		goto out;
	}


	if (le32_to_cpu(csw->tag) != tag) {
		pr_err("sd_reader: TEST UNIT READY tag mismatch\n");
		ret = -EIO;
		goto out;
	}


	pr_info("sd_reader: TEST UNIT READY residue = %u\n",le32_to_cpu(csw->residue));

	pr_info("sd_reader: TEST UNIT READY status = 0x%02x\n",csw->status);


	if (csw->status != 0x00) {
		pr_err("sd_reader: TEST UNIT READY failed\n");
		ret = -EIO;
		goto out;
	}

	pr_info("sd_reader: TEST UNIT READY successful\n");

	ret = 0;

out:

	kfree(csw);
	kfree(cbw);

	return ret;
}


/*
 * READ CAPACITY(10)
 */

static int read_capacity(struct my_device *dev,u32 *max_lba,u32 *block_size)
{
	struct my_cbw *cbw;
	struct my_csw *csw;
	u8 *buffer;

	int actual;
	int ret;

	u32 tag = 0x10000004;

	cbw = kzalloc(sizeof(*cbw), GFP_KERNEL);
	if (!cbw)
		return -ENOMEM;


	csw = kzalloc(sizeof(*csw), GFP_KERNEL);
	if (!csw) {
		kfree(cbw);
		return -ENOMEM;
	}


	buffer = kzalloc(8, GFP_KERNEL);
	if (!buffer) {
		kfree(csw);
		kfree(cbw);
		return -ENOMEM;
	}

	/*
	 * Build READ CAPACITY(10) CBW
	 */

	cbw->signature = cpu_to_le32(CBW_SIGNATURE);
	cbw->tag = cpu_to_le32(tag);

	cbw->data_transfer_length = cpu_to_le32(8);

	cbw->flags = 0x80;

	cbw->lun = 0;

	cbw->cb_length = 10;

	cbw->cb[0] = SCSI_READ_CAPACITY;

	/*
	 * LBA = 0
	 */

	cbw->cb[2] = 0x00;
	cbw->cb[3] = 0x00;
	cbw->cb[4] = 0x00;
	cbw->cb[5] = 0x00;


	pr_info("sd_reader: SCSI READ CAPACITY(10) command sent\n");


	/*
	 * Send CBW
	 */

	ret = usb_bulk_msg(dev->udev,usb_sndbulkpipe(dev->udev, dev->bulk_out),cbw,sizeof(*cbw),&actual,5000);

	if (ret) {
		pr_err("sd_reader: READ CAPACITY CBW failed: %d\n",
				ret);
		goto out;
	}


	if (actual != sizeof(*cbw)) {
		pr_err("sd_reader: READ CAPACITY CBW size error: %d\n",
				actual);
		ret = -EIO;
		goto out;
	}


	pr_info("sd_reader: READ CAPACITY CBW sent\n");


	/*
	 * Receive 8 bytes
	 */

	ret = usb_bulk_msg(dev->udev,usb_rcvbulkpipe(dev->udev, dev->bulk_in),buffer,8,&actual,5000);

	if (ret) {
		pr_err("sd_reader: READ CAPACITY data failed: %d\n",
				ret);
		goto out;
	}


	pr_info("sd_reader: READ CAPACITY received %d bytes\n",
			actual);


	if (actual != 8) {
		pr_err("sd_reader: READ CAPACITY size error: %d\n",actual);
		ret = -EIO;
		goto out;
	}

	print_hex_dump(KERN_INFO,"sd_reader: READ CAPACITY data: ",DUMP_PREFIX_OFFSET,16,1,buffer,8,true);

	/*
	 * First 4 bytes = Maximum LBA
	 *
	 * SCSI uses Big Endian.
	 */

	*max_lba =
		((u32)buffer[0] << 24) |
		((u32)buffer[1] << 16) |
		((u32)buffer[2] << 8) |
		buffer[3];


	/*
	 * Next 4 bytes = Block size
	 */

	*block_size =
		((u32)buffer[4] << 24) |
		((u32)buffer[5] << 16) |
		((u32)buffer[6] << 8) |
		buffer[7];


	pr_info("sd_reader: Maximum LBA = %u\n",
			*max_lba);

	pr_info("sd_reader: Block Size  = %u bytes\n",
			*block_size);


	/*
	 * Receive CSW
	 */

	ret = usb_bulk_msg(dev->udev,usb_rcvbulkpipe(dev->udev, dev->bulk_in),csw,sizeof(*csw),&actual,5000);
	if (ret) {
		pr_err("sd_reader: READ CAPACITY CSW failed: %d\n",
				ret);
		goto out;
	}

	pr_info("sd_reader: READ CAPACITY CSW received %d bytes\n",
			actual);


	if (actual != sizeof(*csw)) {
		pr_err("sd_reader: READ CAPACITY CSW size error: %d\n",
				actual);
		ret = -EIO;
		goto out;
	}


	if (le32_to_cpu(csw->signature) != CSW_SIGNATURE) {
		pr_err("sd_reader: Invalid READ CAPACITY CSW signature\n");
		ret = -EIO;
		goto out;
	}


	if (le32_to_cpu(csw->tag) != tag) {
		pr_err("sd_reader: READ CAPACITY CSW tag mismatch\n");
		ret = -EIO;
		goto out;
	}


	pr_info("sd_reader: READ CAPACITY residue = %u\n",le32_to_cpu(csw->residue));

	pr_info("sd_reader: READ CAPACITY status = 0x%02x\n",csw->status);

	if (csw->status != 0) {
		pr_err("sd_reader: READ CAPACITY command failed\n");
		ret = -EIO;
		goto out;
	}


	pr_info("sd_reader: READ CAPACITY successful\n");

	ret = 0;

out:

	kfree(buffer);
	kfree(csw);
	kfree(cbw);

	return ret;
}


/*
 * ---------------------------------------------------------
 * READ ONE SECTOR
 * ---------------------------------------------------------
 */

static int read_sector(struct my_device *dev,u32 lba,u8 *buffer)
{
	struct my_cbw *cbw;
	struct my_csw *csw;

	int actual;
	int ret;

	u32 tag = 0x10000005;


	cbw = kzalloc(sizeof(*cbw), GFP_KERNEL);
	if (!cbw)
		return -ENOMEM;


	csw = kzalloc(sizeof(*csw), GFP_KERNEL);
	if (!csw) {
		kfree(cbw);
		return -ENOMEM;
	}


	/*
	 * Build READ(10) CBW
	 */

	cbw->signature = cpu_to_le32(CBW_SIGNATURE);
	cbw->tag = cpu_to_le32(tag);

	cbw->data_transfer_length =cpu_to_le32(SECTOR_SIZE);

	cbw->flags = 0x80;

	cbw->lun = 0;

	cbw->cb_length = 10;

	cbw->cb[0] = SCSI_READ10;


	/*
	 * LBA is Big Endian
	 */

	cbw->cb[2] = (lba >> 24) & 0xff;
	cbw->cb[3] = (lba >> 16) & 0xff;
	cbw->cb[4] = (lba >> 8) & 0xff;
	cbw->cb[5] = lba & 0xff;


	/*
	 * Transfer length = 1 sector
	 */

	cbw->cb[7] = 0x00;
	cbw->cb[8] = 0x01;


	pr_info("sd_reader: READ(10) LBA=%u\n", lba);


	/*
	 * Send CBW
	 */

	ret = usb_bulk_msg(dev->udev,usb_sndbulkpipe(dev->udev, dev->bulk_out),cbw,sizeof(*cbw),&actual,5000);

	if (ret) {
		pr_err("sd_reader: READ(10) CBW failed: %d\n",
				ret);
		goto out;
	}


	if (actual != sizeof(*cbw)) {
		pr_err("sd_reader: READ(10) CBW size error: %d\n",actual);
		ret = -EIO;
		goto out;
	}


	pr_info("sd_reader: READ(10) CBW sent\n");


	/*
	 * Receive sector
	 */

	ret = usb_bulk_msg(dev->udev,usb_rcvbulkpipe(dev->udev, dev->bulk_in),buffer,SECTOR_SIZE,&actual,5000);

	if (ret) {
		pr_err("sd_reader: READ(10) data failed: %d\n",
				ret);

		if (ret == -EPIPE) {
			pr_err("sd_reader: BULK IN endpoint stalled\n");

			usb_clear_halt(dev->udev,usb_rcvbulkpipe(dev->udev,dev->bulk_in));
		}
		goto out;
	}

	pr_info("sd_reader: READ(10) received %d bytes\n",actual);
	if (actual != SECTOR_SIZE) {
		pr_err("sd_reader: Expected 512 bytes, got %d\n",actual);
		ret = -EIO;
		goto out;
	}


	print_hex_dump(KERN_INFO,"sd_reader: Sector 0: ",DUMP_PREFIX_OFFSET,16,1,buffer,SECTOR_SIZE,true);


	/*
	 * Receive CSW
	 */

	ret = usb_bulk_msg(dev->udev,usb_rcvbulkpipe(dev->udev, dev->bulk_in),csw,sizeof(*csw),&actual,5000);

	if (ret) {
		pr_err("sd_reader: READ(10) CSW failed: %d\n",
				ret);
		goto out;
	}


	pr_info("sd_reader: READ(10) CSW received %d bytes\n",actual);


	if (actual != sizeof(*csw)) {
		pr_err("sd_reader: READ(10) CSW size error: %d\n",
				actual);
		ret = -EIO;
		goto out;
	}


	if (le32_to_cpu(csw->signature) != CSW_SIGNATURE) {
		pr_err("sd_reader: Invalid READ(10) CSW signature\n");
		ret = -EIO;
		goto out;
	}


	if (le32_to_cpu(csw->tag) != tag) {
		pr_err("sd_reader: READ(10) CSW tag mismatch\n");
		ret = -EIO;
		goto out;
	}


	pr_info("sd_reader: READ(10) residue = %u\n",le32_to_cpu(csw->residue));

	pr_info("sd_reader: READ(10) status = 0x%02x\n",csw->status);


	if (csw->status != 0) {
		pr_err("sd_reader: READ(10) command failed\n");
		ret = -EIO;
		goto out;
	}

	pr_info("sd_reader: READ(10) successful\n");

	ret = 0;

out:

	kfree(csw);
	kfree(cbw);

	return ret;
}


/*
 * ---------------------------------------------------------
 * ANALYZE SECTOR 0
 * ---------------------------------------------------------
 */

static void analyze_sector0(u8 *buffer)
{
	u16 signature;

	if (!buffer)
		return;


	signature = buffer[510] | ((u16)buffer[511] << 8);


	pr_info("----------------------------------\n");
	pr_info("       SECTOR 0 ANALYSIS\n");
	pr_info("----------------------------------\n");


	pr_info("MBR signature = 0x%04x\n",signature);


	if (signature == 0xAA55) {

		pr_info("Valid MBR found\n");
	} else {

		pr_info("No MBR signature found\n");
		pr_info("This could be GPT or another boot sector\n");
	}


	pr_info("----------------------------------\n");
}
/*
static int my_usb_resume(struct usb_interface *interface)
{
	struct my_device *dev;

	dev = usb_get_intfdata(interface);

	if (!dev)
		return 0;

	pr_info("sd_reader: USB resume\n");

	pr_info("sd_reader: USB speed after resume = %d\n",dev->udev->speed);
	return 0;
}
*/
/*
 * ---------------------------------------------------------
 * USB PROBE
 * ---------------------------------------------------------
 */

static int my_usb_probe(struct usb_interface *interface,const struct usb_device_id *id)
{
	struct usb_device *udev;
	struct usb_host_interface *iface;
	struct usb_endpoint_descriptor *ep;
	struct my_device *dev;

	u8 *buffer;

	u32 max_lba;
	u32 block_size;

	u64 total_blocks;
	u64 capacity_bytes; //total capacity in sd card 
	int i;
	int ret;
	pr_info("sd_reader: USB device detected\n");
	udev = interface_to_usbdev(interface);

	iface = interface->cur_altsetting; 
	dev = kzalloc(sizeof(*dev), GFP_KERNEL);
	if (!dev)
		return -ENOMEM;
	dev->udev = udev;
	dev->interface = interface;
	/*
	 * Find bulk endpoints
	 */
	pr_info("new: In probe\n");
	struct usb_host_endpoint *hep;
	for (i = 0; i < iface->desc.bNumEndpoints; i++) {

		hep = &iface->endpoint[i];
		ep = &hep->desc;

		if (usb_endpoint_is_bulk_in(ep)) {

			dev->bulk_in = ep->bEndpointAddress;

			pr_info("sd_reader: BULK IN = 0x%02x\n",dev->bulk_in);

			/*
			 * SuperSpeed companion descriptor
			 */
			pr_info("sd_reader: IN SS Companion:\n");

			pr_info("  bMaxBurst = %u\n",hep->ss_ep_comp.bMaxBurst);

			pr_info("  bmAttributes = 0x%02x\n",hep->ss_ep_comp.bmAttributes);

			pr_info("  wBytesPerInterval = %u\n",le16_to_cpu(hep->ss_ep_comp.wBytesPerInterval));
		}
		else if (usb_endpoint_is_bulk_out(ep)) {
			dev->bulk_out = ep->bEndpointAddress;
			pr_info("sd_reader: BULK OUT = 0x%02x\n",dev->bulk_out);
			/*
			 * SuperSpeed companion descriptor
			 */
			pr_info("sd_reader: OUT SS Companion:\n");
			pr_info("  bMaxBurst = %u\n",hep->ss_ep_comp.bMaxBurst);
			pr_info("  bmAttributes = 0x%02x\n",hep->ss_ep_comp.bmAttributes);
			pr_info("  wBytesPerInterval = %u\n",le16_to_cpu(hep->ss_ep_comp.wBytesPerInterval));
		}
	}
	if (!dev->bulk_in || !dev->bulk_out) {
		pr_err("sd_reader: Bulk endpoints not found\n");
		kfree(dev);
		return -ENODEV;
	}
	/*
	 * Allocate sector buffer
	 */
	buffer = kzalloc(SECTOR_SIZE, GFP_KERNEL);
	if (!buffer) {
		kfree(dev);
		return -ENOMEM;
	}
	//Store the 
	usb_set_intfdata(interface, dev);
	/*
	 * -----------------------------------------------------
	 * 1. INQUIRY
	 * -----------------------------------------------------
	 */

	pr_info("sd_reader: Starting INQUIRY\n");

	ret = inquiry(dev);

	if (ret) {
		pr_err("sd_reader: INQUIRY command failed: %d\n",ret);
		goto probe_error;
	}
	/*
	 * -----------------------------------------------------
	 * 2. TEST UNIT READY
	 * -----------------------------------------------------
	 */

	pr_info("sd_reader: Starting TEST UNIT READY\n");

	ret = test_unit_ready(dev);
	if (ret) {

		pr_err("sd_reader: TEST UNIT READY failed\n");
		/*
		 * Ask the device why it is not ready.
		 */
		ret = request_sense(dev);
		if (ret) {
			pr_err("sd_reader: REQUEST SENSE failed: %d\n",ret);
		}
		/*

 * Some card readers report UNIT ATTENTION after
		 * media insertion/re
		 * moval.
		 *
		 * Give the reader a short time and retry TUR.
		 */

		pr_info("sd_reader: Retrying TEST UNIT READY\n");
		msleep(500);
		ret = test_unit_ready(dev);
		if (ret) {
			pr_info("sd_reader: Media is not ready\n");
			pr_info("sd_reader: Driver attached without media\n");

			kfree(buffer);
			pr_info("sd_reader: Driver successfully attached\n");
			return 0;
		}
	}
	pr_info("sd_reader: Before delay\n");
	//msleep(4000);
	pr_info("sd_reader: After delay\n");

	pr_info("sd_reader: Starting READ CAPACITY(10)\n");
	ret = read_capacity(dev,&max_lba,&block_size);
	if (ret) {
		pr_err("sd_reader: READ CAPACITY command failed: %d\n",ret);
		goto probe_error;
	}
	/*
	 * -----------------------------------------------------
	 * SD CARD INFORMATION
	 * -----------------------------------------------------
	 */
	total_blocks = (u64)max_lba + 1;
	capacity_bytes =total_blocks * block_size;

	pr_info("----------------------------------\n");
	pr_info("SD CARD INFORMATION\n");
	pr_info("----------------------------------\n");

	pr_info("Maximum LBA  : %u\n",max_lba);
	pr_info("Block size   : %u bytes\n",block_size);

	pr_info("Total blocks : %llu\n",(unsigned long long)total_blocks);
	pr_info("Capacity     : %llu bytes\n",(unsigned long long)capacity_bytes);
	pr_info("----------------------------------\n");
	/*
	 * -----------------------------------------------------
	 * 4. READ LBA 0
	 * -----------------------------------------------------
	 */
	pr_info("sd_reader: Reading LBA 0\n");
	ret = read_sector(dev,0,buffer);
	if (ret) {
		pr_err("sd_reader: READ LBA 0 failed: %d\n",ret);
		goto probe_error;
	}
	/*
	 * -----------------------------------------------------
	 * 5. ANALYZE SECTOR 0
	 * -----------------------------------------------------
	 */
	analyze_sector0(buffer);
	kfree(buffer);
	pr_info("sd_reader: Driver successfully attached\n");
	return 0;
probe_error:
	kfree(buffer);
	usb_set_intfdata(interface, NULL);
	kfree(dev);
	return ret;
}
/*
 * ---------------------------------------------------------
 * USB DISCONNECT
 * ---------------------------------------------------------
 */

static void my_usb_disconnect(struct usb_interface *interface)
{
	struct my_device *dev;
	dev = usb_get_intfdata(interface);
	usb_set_intfdata(interface, NULL);
	kfree(dev);
	pr_info("sd_reader: Device disconnected\n");
}


/*
 * ---------------------------------------------------------
 * USB ID TABLE
 * ---------------------------------------------------------
 */

static const struct usb_device_id my_usb_table[] = {
	{
		USB_DEVICE(VENDOR_ID, PRODUCT_ID)
	},
	{}
};
MODULE_DEVICE_TABLE(usb, my_usb_table);


/*
 * ---------------------------------------------------------
 * USB DRIVER
 * ---------------------------------------------------------
 */

static struct usb_driver my_usb_driver = {

	.name = "my_sd_reader",
	.id_table = my_usb_table,
	.probe = my_usb_probe,
	.disconnect = my_usb_disconnect,
};


module_usb_driver(my_usb_driver);

//MODULE_LICENSE("GPL");

MODULE_AUTHOR("Satheesh");

MODULE_DESCRIPTION("Simple USB SD card reader using Bulk Only Transport");