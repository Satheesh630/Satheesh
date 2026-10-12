#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/device.h>
#define DEVICE_NAME "Sample Device"

static dev_t devnum;
static struct cdev mydev;
static struct class *class;
struct file_operations fops={.owner=THIS_MODULE};
static int major;
int __init my_init(void)
{
	major=register_chrdev(0,DEVICE_NAME,&fops);
	pr_info("major : %d\n",major);
	return 0;
}
void __exit my_exit(void)
{
	unregister_chrdev(major,DEVICE_NAME);
}
module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Satheesh");
MODULE_DESCRIPTION("practicing drivers");
