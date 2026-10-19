#ifndef HEADER_H
#define HEADER_H

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/usb/uas.h>
//#include <linux/printk.h>

#define VENDOR_ID   0x0bda
#define PRODUCT_ID  0x9210

#define DEVICE_NAME "superspeed_uas"

#define EP_CMD       0x04
#define EP_STATUS    0x83
#define EP_DATA_IN   0x81
#define EP_DATA_OUT  0x02

#define UAS_STREAM_ID 1

#define INQUIRY_LENGTH 96

struct uas_device {
    struct usb_device *udev;
    struct usb_interface *interface;

    struct usb_host_endpoint *command_ep;
    struct usb_host_endpoint *data_out_ep;
    struct usb_host_endpoint *data_in_ep;
    struct usb_host_endpoint *status_ep;

    unsigned int command_streams;
    unsigned int data_in_streams;
    unsigned int data_out_streams;
    unsigned int status_streams;

    unsigned int max_streams;

    int interface_number;
    int alternate_setting;

    unsigned int next_tag;

    struct urb *cmd_urb;
    struct urb *data_in_urb;
    struct urb *status_urb;
    struct uas_command_iu *cmd_iu;
    u8 *data_in_buf;
    u8 *status_buf;
};
/*
 * UAS Command IU
 *
 * 0       : IU ID
 * 1       : Reserved
 * 2-3     : Tag
 * 4       : Priority / Attribute
 * 5       : Reserved
 * 6-7     : Additional CDB length / reserved area
 * 8-15    : LUN
 * 16-31   : CDB
 */
struct uas_command_iu {
    u8      iu_id;
    u8      reserved;
    __be16  tag;
    u8      prio_attr;
    u8      len;
    u8      reserved2[2];
    u8      lun[8];
    u8      cdb[16];
} __packed;

int find_usb_information(struct usb_host_interface *iface,struct uas_device *my_uas);
int uas_inquiry(struct uas_device *dev);
void print_usb_speed(struct usb_device *udev);
#endif