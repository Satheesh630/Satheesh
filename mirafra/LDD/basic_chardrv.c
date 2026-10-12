#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/cdev.h>

MODULE_DESCRIPTION("Simple character driver");
MODULE_AUTHOR("Satheesh Kumar");
MODULE_LICENSE("GPL");
#define DEVICE_NAME "CHINTU"
#define CLASS_NAME "CHINTU_BHAI"
static dev_t devnum;
static struct cdev dev;
static struct class *Class;
static struct device * my_device;

static struct file_operations fops={.owner=THIS_MODULE};
static int __init my_init(void)
{
	int ret = alloc_chrdev_region(&devnum,0,1,DEVICE_NAME);
	if(ret<0)
	{
		pr_info("failed to allocate major and minor number\n");
		
		return ret;
	}
	pr_info("major:%d minor:%d\n",MAJOR(devnum),MINOR(devnum));
	cdev_init(&dev,&fops);
	cdev_add(&dev,&devnum,1);
	Class=class_create(DEVICE_NAME);
	if(IS_ERR(Class))
	{
		pr_info("Error occured while creating class\n");
		unregister_chrdev_region(devnum,1);
	}
	my_device=device_create(Class,NULL,devnum,NULL,CLASS_NAME);
	if(IS_ERR(my_device))
	{
		pr_err("Failed to create device\n");
		class_destroy(Class);
		cdev_del(&dev);
		unregister_chrdev_region(devnum,1);
	}
	return 0;
}
static void __exit my_exit(void)
{
	device_destroy(Class,devnum);
	class_destroy(Class);
	cdev_del(&dev);
	unregister_chrdev_region(devnum,1);
}

module_init(my_init);
module_exit(my_exit);







