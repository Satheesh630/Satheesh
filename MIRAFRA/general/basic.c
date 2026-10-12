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
int __init my_init(void)
{
	int ret=alloc_chrdev_region(&devnum,0,1,DEVICE_NAME);
	if(ret<0)
	{
		pr_err("Failed to allocate major minor numbers\n");
		return ret;
	}
	pr_info("Major %d   Minor %d  \n",MAJOR(devnum),MINOR(devnum));
	cdev_init(&mydev,&fops);
	ret=cdev_add(&mydev,&devnum,1);
	if(ret<0)
	{
		pr_info("Failed to add to cdev\n");
		return ret;
	}
	class= class_create(DEVICE_NAME);
	if(IS_ERR(class))
	{
		pr_err("Failed to create class\n");
		return class;
	}	
	return 0;
}
void __exit my_exit(void)
{
	pr_info("Exiting\n");
	cdev_del(&mydev);
	class_destroy(class);
	unregister_chrdev_region(&devnum,1);
}
module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Satheesh");
MODULE_DESCRIPTION("practicing drivers");
