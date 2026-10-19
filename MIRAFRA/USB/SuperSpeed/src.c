#include "header.h"

static void uas_command_complete(struct urb *urb);
static void uas_data_in_complete(struct urb *urb);
static void uas_status_complete(struct urb *urb);

/* Get the UAS endpoints and stream information from the selected alt setting. */
  void print_usb_speed(struct usb_device *udev)
    {
        dev_info(&udev->dev, "Current USB speed: %s\n",usb_speed_string(udev->speed));
    }
int find_usb_information(struct usb_host_interface *iface, struct uas_device *my_uas)
{
    int i;

    my_uas->alternate_setting = iface->desc.bAlternateSetting;
    my_uas->interface_number = iface->desc.bInterfaceNumber;

    for (i = 0; i < iface->desc.bNumEndpoints; i++) {

        struct usb_host_endpoint *hep;
        struct usb_endpoint_descriptor *ep;
        unsigned int exponent;
        unsigned int streams;

        hep = &iface->endpoint[i];
        ep = &hep->desc;

        pr_info("Endpoint[%d]\n", i);

        pr_info("  Address       : 0x%02x\n",ep->bEndpointAddress);

        pr_info("  Number        : %u\n",usb_endpoint_num(ep));

        pr_info("  Direction     : %s\n",usb_endpoint_dir_in(ep) ? "IN" : "OUT");

        pr_info("  Transfer type : %u\n",usb_endpoint_type(ep));

        pr_info("  Attributes    : 0x%02x\n",ep->bmAttributes);

        exponent = hep->ss_ep_comp.bmAttributes & 0x1f;

        if (exponent)
            streams = 1U << exponent;
        else
            streams = 0;

        pr_info("  SS bmAttributes : 0x%02x\n",hep->ss_ep_comp.bmAttributes);

        pr_info("  Max Streams     : %u\n",streams);

        if (ep->bEndpointAddress == EP_DATA_OUT) {

            my_uas->data_out_ep = hep;
            my_uas->data_out_streams = streams;
            pr_info("DATA OUT endpoint\n");
        }
        else if (ep->bEndpointAddress == EP_DATA_IN) {
            my_uas->data_in_ep = hep;
            my_uas->data_in_streams = streams;
            pr_info("DATA IN endpoint\n");
        }
        else if (ep->bEndpointAddress == EP_STATUS) {

            my_uas->status_ep = hep;
            my_uas->status_streams = streams;
            pr_info("  ==> STATUS endpoint\n");
        }
        else if (ep->bEndpointAddress == EP_CMD) {

            my_uas->command_ep = hep;
            my_uas->command_streams = 0;
            pr_info("  ==> COMMAND endpoint\n");
        }
    }

    my_uas->max_streams = my_uas->status_streams;

    if (my_uas->data_in_streams > my_uas->max_streams)
                my_uas->max_streams = my_uas->data_in_streams;

    if (my_uas->data_out_streams > my_uas->max_streams)
                my_uas->max_streams = my_uas->data_out_streams;

    pr_info("\n-------------UAS INFORMATION -----------------\n");

    pr_info("Command EP       : 0x%02x\n",my_uas->command_ep->desc.bEndpointAddress);

    pr_info("Command Streams  : %u\n",my_uas->command_streams);

    pr_info("Data IN EP       : 0x%02x\n",my_uas->data_in_ep->desc.bEndpointAddress);

    pr_info("Data IN Streams  : %u\n",my_uas->data_in_streams);

    pr_info("Data OUT EP      : 0x%02x\n",my_uas->data_out_ep->desc.bEndpointAddress);

    pr_info("Data OUT Streams : %u\n",my_uas->data_out_streams);

    pr_info("Status EP        : 0x%02x\n",my_uas->status_ep->desc.bEndpointAddress);

    pr_info("Status Streams   : %u\n",my_uas->status_streams);

    pr_info("Maximum Streams  : %u\n",my_uas->max_streams);

    pr_info("-----------------------------------------\n");
    my_uas->next_tag = 0;
    return 0;
}

/* Send a simple TEST UNIT READY command. */
int uas_test_unit_ready(struct uas_device *dev)
{

    int ret;
    struct urb *cmd_urb = usb_alloc_urb(0, GFP_KERNEL);
    struct urb *status_urb = usb_alloc_urb(0, GFP_KERNEL);

    if (!cmd_urb || !status_urb) {
        ret = -ENOMEM;
        goto error;
    }
    dev->cmd_urb = cmd_urb;
    dev->status_urb = status_urb;

    struct uas_command_iu *cmd_iu = kzalloc(sizeof(*cmd_iu), GFP_KERNEL);

    dev->cmd_iu = cmd_iu;


    u8 *status_buf = kzalloc(64, GFP_KERNEL);
    dev->status_buf = status_buf;

    if (!cmd_iu || !status_buf) {
        ret = -ENOMEM;
        goto error;
    }

    u16 tag;
    tag = ++dev->next_tag;

    cmd_iu->iu_id = 0x01;
    cmd_iu->tag = cpu_to_le16(tag);

    cmd_iu->cdb[0] = 0x00;

    usb_fill_bulk_urb(status_urb,dev->udev,usb_rcvbulkpipe(dev->udev, dev->status_ep->desc.bEndpointAddress),status_buf,64,uas_status_complete,dev);

    status_urb->stream_id = 1;
    pr_info("UAS: Submitting STATUS URB\n");
    pr_info("    endpoint = 0x%02x\n",dev->status_ep->desc.bEndpointAddress);
    pr_info("    stream   = %u\n",status_urb->stream_id);
    pr_info("    length   = %u\n",status_urb->transfer_buffer_length);

    ret = usb_submit_urb(status_urb, GFP_KERNEL);

    if (ret) {
        pr_err("UAS: Status URB submit failed: %d\n", ret);

        goto error;
    }
    pr_info("UAS: STATUS URB submitted successfully\n");

    usb_fill_bulk_urb(cmd_urb,dev->udev,usb_sndbulkpipe(dev->udev, dev->command_ep->desc.bEndpointAddress),cmd_iu,sizeof(*cmd_iu),uas_command_complete,dev);

    cmd_urb->stream_id = 0;
    pr_info("UAS: Submitting COMMAND URB\n");
    pr_info("    endpoint = 0x%02x\n",dev->command_ep->desc.bEndpointAddress);
    pr_info("    stream   = %u\n",cmd_urb->stream_id);
    pr_info("    length   = %u\n",cmd_urb->transfer_buffer_length);
    
        pr_info("UAS: Command IU size = %zu\n", sizeof(*cmd_iu));
    ret = usb_submit_urb(cmd_urb, GFP_KERNEL);
    if (ret) {
        pr_err("UAS: Command URB submit failed: %d\n", ret);
        usb_kill_urb(status_urb);
        goto error;
    }
    pr_info("UAS: TEST UNIT READY sent, tag=%u\n",tag);
    return 0;
error:    

    if (cmd_urb)
        usb_free_urb(cmd_urb);
    if (status_urb)
        usb_free_urb(status_urb);
    kfree(cmd_iu);
    kfree(status_buf);
    return ret;
}

/* Send a SCSI INQUIRY command and receive the response. */
int uas_inquiry(struct uas_device *dev)
{
    int ret = 0;
    u16 tag;

    struct urb *cmd_urb = NULL;
    struct urb *data_in_urb = NULL;
    struct urb *status_urb = NULL;

    struct uas_command_iu *cmd_iu = NULL;

    u8 *data_in_buf = NULL;
    u8 *status_buf = NULL;

    cmd_urb = usb_alloc_urb(0, GFP_KERNEL);
    data_in_urb = usb_alloc_urb(0, GFP_KERNEL);
    status_urb = usb_alloc_urb(0, GFP_KERNEL);

    if (!cmd_urb || !data_in_urb || !status_urb) {
        ret = -ENOMEM;
        goto error;
    }

    cmd_iu = kzalloc(sizeof(*cmd_iu), GFP_KERNEL);

    if (!cmd_iu) {
        ret = -ENOMEM;

        goto error;
    }

    data_in_buf = kzalloc(INQUIRY_LENGTH, GFP_KERNEL);

    if (!data_in_buf) {
        ret = -ENOMEM;
        goto error;
    }

    status_buf = kzalloc(64, GFP_KERNEL);

    if (!status_buf) {
        ret = -ENOMEM;
        goto error;
    }

    dev->cmd_urb = cmd_urb;
    dev->data_in_urb = data_in_urb;
    dev->status_urb = status_urb;

    dev->cmd_iu = cmd_iu;

    dev->data_in_buf = data_in_buf;
    dev->status_buf = status_buf;

    tag = ++dev->next_tag;

    if (tag == 0)
        tag = ++dev->next_tag;

    cmd_iu->iu_id = 0x01;
    cmd_iu->tag = cpu_to_be16(tag);
    cmd_iu->prio_attr = 0x00;
    cmd_iu->len = 0;

    cmd_iu->cdb[0] = 0x12;
    cmd_iu->cdb[1] = 0x00;
    cmd_iu->cdb[2] = 0x00;
    cmd_iu->cdb[3] = 0x00;
    cmd_iu->cdb[4] = INQUIRY_LENGTH;
    cmd_iu->cdb[5] = 0x00;

    usb_fill_bulk_urb(status_urb,dev->udev,usb_rcvbulkpipe(dev->udev,dev->status_ep->desc.bEndpointAddress),status_buf,64,uas_status_complete,dev);

    status_urb->stream_id = tag;

    pr_info("UAS: Submitting STATUS URB\n");

    pr_info("    endpoint = 0x%02x\n",dev->status_ep->desc.bEndpointAddress);

    pr_info("    stream   = %u\n",status_urb->stream_id);

    pr_info("    length   = %u\n",status_urb->transfer_buffer_length);

    ret = usb_submit_urb(status_urb, GFP_KERNEL);

    if (ret) {
        pr_err("UAS: STATUS URB submit failed: %d\n", ret);
        goto error;
    }

    pr_info("UAS: STATUS URB submitted successfully\n");

    usb_fill_bulk_urb(data_in_urb,dev->udev,usb_rcvbulkpipe(dev->udev,dev->data_in_ep->desc.bEndpointAddress),data_in_buf,INQUIRY_LENGTH,uas_data_in_complete,dev);

    data_in_urb->stream_id = tag;

    pr_info("UAS: Submitting DATA-IN URB\n");

    pr_info("    endpoint = 0x%02x\n",dev->data_in_ep->desc.bEndpointAddress);
    pr_info("    stream   = %u\n",data_in_urb->stream_id);
    pr_info("    length   = %u\n",data_in_urb->transfer_buffer_length);

    ret = usb_submit_urb(data_in_urb, GFP_KERNEL);

    if (ret) {
        pr_err("UAS: DATA-IN URB submit failed: %d\n", ret);
        usb_kill_urb(status_urb);
        goto error;
    }

    pr_info("UAS: DATA-IN URB submitted successfully\n");
    usb_fill_bulk_urb(cmd_urb,dev->udev,usb_sndbulkpipe(dev->udev,dev->command_ep->desc.bEndpointAddress),cmd_iu,sizeof(*cmd_iu),uas_command_complete,dev);
    cmd_urb->stream_id = 0;
    pr_info("UAS: Submitting INQUIRY COMMAND URB\n");

    pr_info("    endpoint = 0x%02x\n",dev->command_ep->desc.bEndpointAddress);

    pr_info("    stream   = %u\n",cmd_urb->stream_id);

    pr_info("    length   = %u\n",cmd_urb->transfer_buffer_length);

    pr_info("UAS: Command IU size = %zu\n",sizeof(*cmd_iu));

    ret = usb_submit_urb(cmd_urb, GFP_KERNEL);

    if (ret) {
        pr_err("UAS: COMMAND URB submit failed: %d\n", ret);

        usb_kill_urb(data_in_urb);
        usb_kill_urb(status_urb);

        goto error;
    }

    pr_info("UAS: INQUIRY command submitted, tag=%u\n", tag);

    return 0;

error:

    if (cmd_urb)
        usb_kill_urb(cmd_urb);

    if (data_in_urb)
        usb_kill_urb(data_in_urb);

    if (status_urb)
        usb_kill_urb(status_urb);

    if (dev->cmd_urb == cmd_urb)
        dev->cmd_urb = NULL;

    if (dev->data_in_urb == data_in_urb)
        dev->data_in_urb = NULL;

    if (dev->status_urb == status_urb)
        dev->status_urb = NULL;

    if (dev->cmd_iu == cmd_iu)
        dev->cmd_iu = NULL;

    if (dev->data_in_buf == data_in_buf)
        dev->data_in_buf = NULL;

    if (dev->status_buf == status_buf)
        dev->status_buf = NULL;
    usb_free_urb(cmd_urb);
    usb_free_urb(data_in_urb);
    usb_free_urb(status_urb);

    kfree(cmd_iu);
    kfree(data_in_buf);
    kfree(status_buf);

    return ret;
}

/* Command URB completion callback. */
static void uas_command_complete(struct urb *urb)
{
    if (urb->status) {
        pr_err("UAS: COMMAND URB failed: %d\n",urb->status);
        return;
    }

    pr_info("UAS: INQUIRY Command IU transmitted successfully\n");
}

/* Data-IN URB completion callback. */
static void uas_data_in_complete(struct urb *urb)
{
    struct uas_device *dev = urb->context;

    pr_info("UAS: DATA-IN callback called\n");

    pr_info("    status        = %d\n",urb->status);

    pr_info("    actual_length = %u\n",urb->actual_length);

    if (urb->status) {
        pr_err("UAS: DATA-IN URB failed: %d\n",urb->status);
        return;
    }

    pr_info("UAS: INQUIRY data received\n");

    print_hex_dump(KERN_INFO,"UAS INQUIRY: ",DUMP_PREFIX_OFFSET,16,1,urb->transfer_buffer,urb->actual_length,true);

    if (urb->actual_length >= 36) {

        u8 *buf = urb->transfer_buffer;

        pr_info("UAS: INQUIRY INFORMATION\n");

        pr_info("    Peripheral Device Type : 0x%02x\n",buf[0] & 0x1f);

        pr_info("    RMB                    : %u\n",!!(buf[1] & 0x80));

        pr_info("    Version                : 0x%02x\n",buf[2]);

        pr_info("    Response Data Format  : 0x%02x\n",buf[3] & 0x0f);

        pr_info("    Vendor                 : %.8s\n",&buf[8]);

        pr_info("    Product                : %.16s\n",&buf[16]);

        pr_info("    Revision               : %.4s\n",&buf[32]);
    }
}

/* Status URB completion callback. */
static void uas_status_complete(struct urb *urb)
{
    struct uas_device *dev = urb->context;

    pr_info("UAS: STATUS callback called\n");

    pr_info("    status        = %d\n",urb->status);

    pr_info("    actual_length = %u\n",urb->actual_length);

    if (urb->status) {
        pr_err("UAS: STATUS URB failed: %d\n",urb->status);
        return;
    }

    pr_info("UAS: STATUS IU received\n");

    print_hex_dump(
        KERN_INFO,
        "UAS STATUS: ",
        DUMP_PREFIX_OFFSET,
        16,
        1,
        urb->transfer_buffer,
        urb->actual_length,
        true
    );

    if (urb->actual_length >= 16) {

        u8 *buf = urb->transfer_buffer;

        pr_info("UAS: STATUS IU\n");

        pr_info("    IU ID = 0x%02x\n",buf[0]);

        pr_info("    Tag   = %u\n",be16_to_cpup((__be16 *)&buf[2]));

        pr_info("    SCSI status = 0x%02x\n",buf[11]);
    }
}