#include "header.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Satheesh Kumar Namala");
MODULE_DESCRIPTION("SuperSpeed USB Driver with Streams Support");

/* Probe function */
static int my_probe(struct usb_interface *interface,const struct usb_device_id *id)
{
    struct usb_host_interface *iface;
    struct usb_device *udev;
    struct usb_host_endpoint *eps[3];
    struct uas_device *my_uas;
    int ret;

    pr_info("SuperSpeed: Device Probe called\n");

    my_uas = kzalloc(sizeof(*my_uas), GFP_KERNEL);
    if (!my_uas)
        return -ENOMEM;

    udev = interface_to_usbdev(interface);

    my_uas->udev = udev;
    my_uas->interface = interface;
    
    ret = usb_set_interface(udev,interface->cur_altsetting->desc.bInterfaceNumber,1);
    if (ret) {
        pr_err("SuperSpeed: Failed to set interface: %d\n", ret);
        goto err_free_uas;
    }

    /*
     * Get the current alternate setting AFTER usb_set_interface().
     */
    iface = interface->cur_altsetting;

    pr_info("UAS: interface=%u alt=%u endpoints=%u\n",
            iface->desc.bInterfaceNumber,
            iface->desc.bAlternateSetting,
            iface->desc.bNumEndpoints);
    print_usb_speed(udev);
    ret = find_usb_information(iface, my_uas);
    if (ret) {
        pr_err("SuperSpeed: Failed to find USB information: %d\n", ret);
        goto err_free_uas;
    }
    // check wether the required endpoints are found successfully or not
    if (!my_uas->data_out_ep ||!my_uas->data_in_ep ||!my_uas->status_ep) {
        pr_err("UAS: Missing required stream endpoint\n");
        ret = -ENODEV;
        goto err_free_uas;
    }

    pr_info("UAS: data OUT = %p\n", my_uas->data_out_ep);
    pr_info("UAS: data IN  = %p\n", my_uas->data_in_ep);
    pr_info("UAS: status   = %p\n", my_uas->status_ep);

    eps[0] = my_uas->data_out_ep;
    eps[1] = my_uas->data_in_ep;
    eps[2] = my_uas->status_ep;

    ret = usb_alloc_streams(interface,eps,3,32,GFP_KERNEL); // Can also use ARRAY_SIZE(eps) instead of 3
    if (ret < 0) {
        pr_err("SuperSpeed: Failed to allocate streams: %d\n", ret);
        goto err_free_uas;
    }

    pr_info("UAS: usb_alloc_streams returned %d\n", ret);
    usb_set_intfdata(interface, my_uas);
    uas_inquiry(my_uas);

    pr_info("UAS: Probe successful\n");

    return 0;

err_free_streams:
    usb_free_streams(interface,eps,ARRAY_SIZE(eps),GFP_KERNEL);
    usb_set_intfdata(interface, NULL);

err_free_uas:
    kfree(my_uas);

    return ret;
}

/* USB Device ID table */

static const struct usb_device_id super_speed_table[] = {
    { USB_DEVICE(VENDOR_ID, PRODUCT_ID) },
    { }
};

MODULE_DEVICE_TABLE(usb, super_speed_table);


/* Disconnect function */

static void my_disconnect(struct usb_interface *interface)
{
    struct uas_device *my_uas;
    struct usb_host_endpoint *eps[3];

    my_uas = usb_get_intfdata(interface);
    usb_set_intfdata(interface, NULL);

    if (!my_uas)
        return;

    if (my_uas->cmd_urb)
        usb_kill_urb(my_uas->cmd_urb);

    if (my_uas->status_urb)
        usb_kill_urb(my_uas->status_urb);

    if (my_uas->cmd_urb)
        usb_free_urb(my_uas->cmd_urb);

    if (my_uas->status_urb)
        usb_free_urb(my_uas->status_urb);

    kfree(my_uas->cmd_iu);
    kfree(my_uas->status_buf);

    eps[0] = my_uas->data_out_ep;
    eps[1] = my_uas->data_in_ep;
    eps[2] = my_uas->status_ep;

    usb_free_streams(my_uas->interface,eps,ARRAY_SIZE(eps),GFP_KERNEL);

    kfree(my_uas);

    pr_info("SuperSpeed: Device Disconnected\n");
}


/* USB Driver structure */
static struct usb_driver super_speed_driver = {
    .name       = DEVICE_NAME,
    .id_table   = super_speed_table,
    .probe      = my_probe,
    .disconnect = my_disconnect,
};


/* Module registration  macro */
module_usb_driver(super_speed_driver);