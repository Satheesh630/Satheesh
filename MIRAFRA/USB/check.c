//if another driver is already installed and indicates that it is responsible for the device attached ..then 
//...your probe will not get called
//simply the probe function will not get called if another driver has taken claim of this particular device registerd with this device
// struct usb_interface *interface -> this structure already contains the parsed descriptor data of the device(interface descriptor)
static int my_usb_probe(struct usb_interface *interface, const struct usb_device_id *id)
{

    //creating a var for my usb device private structure
    struct my_usb_dev *dev;

    dev = kzalloc(sizeof(*dev), GFP_KERNEL);
    if(!dev)
        return -ENOMEM;

    struct usb_device *udev;
    struct usb_endpoint_descriptor *endpoint_desc; //pointer to a structure that can store the info about the endpoint
    struct usb_host_interface *curr_interface_alt_setting; //pointer to store the curr alternate settings of the interface
    int ret;


    udev = interface_to_usbdev(interface);  //udev will contain the parsed descriptor data and info of the device


    //populate the private data structure(my_usb_dev)
    //step 1 -> increment the refernce count of the usb device we claimed
    dev -> udev = usb_get_dev(udev);
    
    //store the current interface of the usb device in our private usb device data structure
    dev -> intf = interface;

    //usb_set_intfdata -> associate driver specific data with an interface
    usb_set_intfdata(interface, dev);



    printk(KERN_INFO "my_usb_driver: speed = %d\n", udev->speed); //speed for the device enumerated 

    // struct usb_host_interface *usb_altnum_to_altsetting(const struct usb_interface *intf, unsigned int altnum)
    // get the altsetting structure with a given alternate setting number.

    
    curr_interface_alt_setting = interface -> cur_altsetting;  //usb_host_interface contains : 
                                                                    //├── .desc  (interface descriptor)
                                                                    //└── .endpoint[] arrays (endpoints)

    /*Printing some data fromt the current interface*/                                                                

    printk(KERN_INFO "my_usb_driver : from my_usb_driver_probe() : device connected\n");

    printk(KERN_INFO "my_usb_driver: VID:PID = %04x:%04x\n",le16_to_cpu(udev->descriptor.idVendor), le16_to_cpu(udev->descriptor.idProduct));
                                                            //converts to host machine byte ordering() -> le16_to_cpu()


    //printing the device descriptor data
    printk(KERN_INFO "my_usb_driver : dev bLength=%u bDescriptorType=%u bcdUSB=0x%04x\n" , udev -> descriptor.bLength , udev -> descriptor.bDescriptorType , udev -> descriptor.bcdUSB);
    
    if(udev -> descriptor.bLength != 18 || udev->descriptor.bDescriptorType != USB_DT_DEVICE)
    {
        goto err_free;
    }
    
    //printing the class , subclass , protocol for this interface , number of endpoints
    printk(KERN_INFO "my_usb_driver: class=%02x\n", curr_interface_alt_setting->desc.bInterfaceClass);

    printk(KERN_INFO "my_usb_driver: subclass=%02x\n", curr_interface_alt_setting->desc.bInterfaceSubClass);

    printk(KERN_INFO "my_usb_driver: protocol=%02x\n", curr_interface_alt_setting->desc.bInterfaceProtocol);

    printk(KERN_INFO "my_usb_driver: endpoints=%u\n", curr_interface_alt_setting->desc.bNumEndpoints);


    //validate class , subclass and protocol
    if(curr_interface_alt_setting->desc.bInterfaceClass != 0x08 || curr_interface_alt_setting->desc.bInterfaceSubClass != 0x06 || curr_interface_alt_setting->desc.bInterfaceProtocol != 0x50)
    {
        goto err_free;
    }


    //now we are going to get the address of each endpoint associated with this curr altsetting interface 
    // USB data does not go through the interface abstractly — it goes through endpoints.
    //endpoints are in curr_interface_alt_setting->endpoint[i] and the descriptor is  in ..->endpoint[i].desc
    for(int i = 0; i < curr_interface_alt_setting -> desc.bNumEndpoints ; i++)
    {
        endpoint_desc = &curr_interface_alt_setting->endpoint[i].desc;


        printk(KERN_INFO "my_usb_driver: ep[%d] address=0x%02x\n", i , endpoint_desc->bEndpointAddress);

        //store the type of this particular endpoint in the private data structure(ep_in or ep_out)
        if(usb_endpoint_is_bulk_in(endpoint_desc)) //api to check whether the endpoint is IN
        {
            dev -> ep_in = endpoint_desc->bEndpointAddress;
            dev -> maxpkt_in = usb_endpoint_maxp(endpoint_desc);
        }
        else if(usb_endpoint_is_bulk_out(endpoint_desc))  //api to check whether the endpoint is OUT
        {
            dev -> ep_out = endpoint_desc->bEndpointAddress;
            dev -> maxpkt_out = usb_endpoint_maxp(endpoint_desc);
        }

        printk(KERN_INFO "my_usb_driver: ep[%d] attributes=0x%02x\n", i , endpoint_desc->bmAttributes);

        printk(KERN_INFO "my_usb_driver: ep[%d] maxpkt=%d\n", i , usb_endpoint_maxp(endpoint_desc));

        
    }
    if(!dev -> ep_in || !dev -> ep_out)
    {
        goto err_free;
    }


    ret = do_scsi_inquiry(dev);
    if(ret)
    {
        printk(KERN_ERR "my_usb_driver: INQUIRY failed: %d\n", ret);
        // goto err_free;
    }
        


    return 0;

err_free : 
    usb_set_intfdata(interface , NULL);
    usb_put_dev(dev -> udev);  //dec the ref count for the usb device structure
    kfree(dev);
    return -ENODEV;
   
}
