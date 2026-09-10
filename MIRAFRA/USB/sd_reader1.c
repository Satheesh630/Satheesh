#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/usb.h>


#define VENDOR_ID 0x8564
#define PRODUCT_ID 0x4000
static int my_usb_probe(struct usb_interface *interface,const struct usb_device_id *id)
{
	
    struct usb_device *udev;
    struct usb_host_interface *iface_desc;
    struct usb_endpoint_descriptor *endpoint;
    int i;
    
    udev = interface_to_usbdev(interface);
    iface_desc = interface->cur_altsetting;

    pr_info("MY_USB: device detected\n");

    pr_info("VID: 0x%04x\n",
            le16_to_cpu(udev->descriptor.idVendor));

    pr_info("PID: 0x%04x\n",
            le16_to_cpu(udev->descriptor.idProduct));

    pr_info("Bus: %d\n", udev->bus->busnum);
    pr_info("Device address: %d\n", udev->devnum);

    pr_info("Interface number: %d\n",
            iface_desc->desc.bInterfaceNumber);

    pr_info("Interface class: 0x%02x\n",
            iface_desc->desc.bInterfaceClass);

    pr_info("Interface subclass: 0x%02x\n",
            iface_desc->desc.bInterfaceSubClass);

    pr_info("Interface protocol: 0x%02x\n",
            iface_desc->desc.bInterfaceProtocol);

    for (i = 0; i < iface_desc->desc.bNumEndpoints; i++) {

        endpoint = &iface_desc->endpoint[i].desc;

        pr_info("Endpoint %d: address=0x%02x attributes=0x%02x maxpacket=%u\n",
                i,
                endpoint->bEndpointAddress,
                endpoint->bmAttributes,
                usb_endpoint_maxp(endpoint));

        if (usb_endpoint_is_bulk_in(endpoint))
            pr_info("  -> BULK IN endpoint\n");

        if (usb_endpoint_is_bulk_out(endpoint))
            pr_info("  -> BULK OUT endpoint\n");
    }

	

	return 0;
}
static void my_usb_disconnect(struct usb_interface *interface)
{
	pr_info("MY_USB: Device disconnected\n");

}

static const struct usb_device_id my_usb_table[]={
{USB_DEVICE(VENDOR_ID,PRODUCT_ID)},{}};

MODULE_DEVICE_TABLE(usb,my_usb_table);

static struct usb_driver my_usb_driver={.name="my_sd_reader",
					.id_table=my_usb_table, .probe=my_usb_probe,.disconnect=my_usb_disconnect,};
 


module_usb_driver(my_usb_driver);










MODULE_LICENSE("GPL");
MODULE_AUTHOR("Satheesh");
MODULE_DESCRIPTION("Simple driver for sd card reader");

