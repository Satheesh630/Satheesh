struct my_device {
	struct usb_device *udev;
	struct usb_interface *interface;

	u8 bulk_in;
	u8 bulk_out;

	/* Host endpoint structures */
	struct usb_host_endpoint *bulk_in_hc;
	struct usb_host_endpoint *bulk_out_hc;

	/* USB 3.x stream information */
	unsigned int num_streams;
	bool streams_allocated;

	/* SuperSpeed information */
	bool superspeed;
	u8 bulk_in_max_burst;
	u8 bulk_out_max_burst;
	u8 bulk_in_max_stream_exp;
	u8 bulk_out_max_stream_exp;
};


/*
 * ---------------------------------------------------------
 * USB 3.x / SUPERSPEED INFORMATION
 * ---------------------------------------------------------
 */

static void show_superspeed_info(struct my_device *dev)
{
	struct usb_device *udev = dev->udev;
	struct usb_host_endpoint *ep_in;
	struct usb_host_endpoint *ep_out;
	struct usb_ss_ep_comp_descriptor *comp;
	unsigned int max_streams;

	pr_info("----------------------------------\n");
	pr_info("       USB 3.x INFORMATION\n");
	pr_info("----------------------------------\n");

	switch (udev->speed) {

	case USB_SPEED_SUPER:
		pr_info("USB speed      : SuperSpeed (USB 3.x)\n");
		dev->superspeed = true;
		break;

#ifdef USB_SPEED_SUPER_PLUS
	case USB_SPEED_SUPER_PLUS:
		pr_info("USB speed      : SuperSpeedPlus (USB 3.x)\n");
		dev->superspeed = true;
		break;
#endif

	case USB_SPEED_HIGH:
		pr_info("USB speed      : High-Speed (USB 2.0)\n");
		dev->superspeed = false;
		break;

	case USB_SPEED_FULL:
		pr_info("USB speed      : Full-Speed (USB 1.x)\n");
		dev->superspeed = false;
		break;

	case USB_SPEED_LOW:
		pr_info("USB speed      : Low-Speed (USB 1.x)\n");
		dev->superspeed = false;
		break;

	default:
		pr_info("USB speed      : Unknown\n");
		dev->superspeed = false;
		break;
	}

	if (!dev->superspeed) {
		pr_info("SuperSpeed     : NOT ACTIVE\n");
		pr_info("----------------------------------\n");
		return;
	}

	pr_info("SuperSpeed     : ACTIVE\n");

	ep_in = dev->bulk_in_hc;
	ep_out = dev->bulk_out_hc;

	if (!ep_in || !ep_out) {
		pr_err("sd_reader: SuperSpeed endpoints unavailable\n");
		return;
	}

	/*
	 * BULK IN SuperSpeed companion descriptor
	 */

	comp = &ep_in->ss_ep_comp;

	dev->bulk_in_max_burst = comp->bMaxBurst;

	dev->bulk_in_max_stream_exp =
		comp->bmAttributes & 0x1f;

	pr_info("BULK IN endpoint        : 0x%02x\n",
		dev->bulk_in);

	pr_info("BULK IN max burst       : %u\n",
		dev->bulk_in_max_burst);

	pr_info("BULK IN stream exponent : %u\n",
		dev->bulk_in_max_stream_exp);

	if (dev->bulk_in_max_stream_exp) {

		max_streams =
			1U << dev->bulk_in_max_stream_exp;

		pr_info("BULK IN max streams     : %u\n",
			max_streams);

	} else {

		pr_info("BULK IN streams         : Not supported\n");
	}

	/*
	 * BULK OUT SuperSpeed companion descriptor
	 */

	comp = &ep_out->ss_ep_comp;

	dev->bulk_out_max_burst = comp->bMaxBurst;

	dev->bulk_out_max_stream_exp =
		comp->bmAttributes & 0x1f;

	pr_info("BULK OUT endpoint       : 0x%02x\n",
		dev->bulk_out);

	pr_info("BULK OUT max burst      : %u\n",
		dev->bulk_out_max_burst);

	pr_info("BULK OUT stream exponent: %u\n",
		dev->bulk_out_max_stream_exp);

	if (dev->bulk_out_max_stream_exp) {

		max_streams =
			1U << dev->bulk_out_max_stream_exp;

		pr_info("BULK OUT max streams    : %u\n",
			max_streams);

	} else {

		pr_info("BULK OUT streams        : Not supported\n");
	}

	pr_info("----------------------------------\n");
}

// Endpoint Descovary 

for (i = 0; i < iface->desc.bNumEndpoints; i++) {

	ep = &iface->endpoint[i].desc;

	if (usb_endpoint_is_bulk_in(ep)) {

		dev->bulk_in = ep->bEndpointAddress;

		dev->bulk_in_hc = &iface->endpoint[i];

		pr_info(
			"sd_reader: BULK IN = 0x%02x\n",
			dev->bulk_in);

	} else if (usb_endpoint_is_bulk_out(ep)) {

		dev->bulk_out = ep->bEndpointAddress;

		dev->bulk_out_hc = &iface->endpoint[i];

		pr_info(
			"sd_reader: BULK OUT = 0x%02x\n",
			dev->bulk_out);
	}
}


//In probe add 
/*
 * ---------------------------------------------------------
 * USB 3.x SUPERSPEED INFORMATION
 * ---------------------------------------------------------
 */

show_superspeed_info(dev);


//power management 
/*
 * ---------------------------------------------------------
 * USB POWER MANAGEMENT
 * ---------------------------------------------------------
 */

static int my_usb_suspend(struct usb_interface *interface,
			  pm_message_t message)
{
	struct my_device *dev;

	dev = usb_get_intfdata(interface);

	if (!dev)
		return 0;

	pr_info(
		"sd_reader: USB suspend requested\n");

	pr_info("sd_reader: USB speed before suspend = %d\n",dev->udev->speed);

	/*
	 * No transfers should be running here.
	 *
	 * The USB core/xHCI handles the actual
	 * USB 3.x link power state transition.
	 */
	return 0;
}


static int my_usb_resume(struct usb_interface *interface)
{
	struct my_device *dev;

	dev = usb_get_intfdata(interface);

	if (!dev)
		return 0;

	pr_info(
		"sd_reader: USB resume\n");

	pr_info(
		"sd_reader: USB speed after resume = %d\n",
		dev->udev->speed);

	return 0;
}


static int my_usb_reset_resume(struct usb_interface *interface)
{
	struct my_device *dev;

	dev = usb_get_intfdata(interface);

	if (!dev)
		return 0;

	pr_info(
		"sd_reader: USB reset-resume\n");

	/*
	 * A reset-resume can invalidate device-side state.
	 *
	 * Reinitialize BOT state here if necessary.
	 */

	return 0;
}

//Add this after usb_set_intfdata(interface, dev);

/*
 * ---------------------------------------------------------
 * ENABLE USB RUNTIME POWER MANAGEMENT
 * ---------------------------------------------------------
 */

usb_enable_autosuspend(udev);

pr_info("sd_reader: USB autosuspend enabled\n");


//change callbacks 
static struct usb_driver my_usb_driver = {

	.name = "my_sd_reader",

	.id_table = my_usb_table,

	.probe = my_usb_probe,

	.disconnect = my_usb_disconnect,

	.suspend = my_usb_suspend,

	.resume = my_usb_resume,

	.reset_resume = my_usb_reset_resume,

	.supports_autosuspend = 1,
};
