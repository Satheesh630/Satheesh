#include"header.h"

#define PRODUCT_ID 0x22b8
#define VENDOR_ID 0x2e82
#define DEVICE_NAME "Motorola"

#define TEST_UNIT_READY 0x00

static int probe(struct usb_interface *interface, const struct usb_device_id *id)
{
        pr_info("Moto G72 connected\n");
        pr_info("Vendor ID: 0x%04x\n", id->idVendor);
        pr_info("Product ID: 0x%04x\n", id->idProduct);
        return 0;
}
static const struct usb_device_id device_table[]={
    {
        USB_DEVICE(VENDOR_ID,PRODUCT_ID)
    },
    {}
};
MODULE_DEVICE_TABLE(usb,device_table);

static struct usb_driver motorola_driver = {
    .name=DEVICE_NAME,
    .id_table=device_table,
    .probe=probe,
};
module_usb_driver(motorola_driver);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Chintu");
MODULE_DESCRIPTION("Motorola G72 USB Driver");
