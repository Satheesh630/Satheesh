#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/cdev.h>
#include<linux/interrupt.h>
#define DEVICE_NAME "Unseen Device by Chintu"
#define CLASS_NAME "unseen class"
#define IRQ_NUM 1 //Keyboard interrupt

static dev_t my_dev;
static struct cdev my_cdev;
static struct class *my_class;
static struct device *my_device;
static char *ptr;


static ssize_t my_write(struct file *file,const char __user *user,size_t count,loff_t *pos)
{
	pr_info("write callback called\n");
	return count;

}
static ssize_t my_read(struct file* file,char __user *user,size_t  count,loff_t *pos)
{
	ptr=kmalloc(100,GFP_KERNEL);
	strcpy(ptr,"Hello Im from kernel\n");
	int len=strlen(ptr);
	if(*pos >0)
		return 0;
	if(count <len)
		len=count;	
	int ret=copy_to_user(user,ptr,strlen(ptr));
	if(ret !=0)
	{
		pr_info("copy to user failed\n");
		return -EFAULT;
	}
	*pos+=count;
	return len;
}	
static irqreturn_t my_isr(int irq,void *dev_id)
{
	
	pr_info("Keyboard interrupt triggered\n");
	return IRQ_HANDLED;
}
static irqreturn_t my_isr1(int irq,void *dev_id)
{
	pr_info("In isr 1\n");
	return IRQ_HANDLED;
}
static irqreturn_t my_isr2(int irq,void *dev_id)
{
	pr_info("In isr 2\n");
	return IRQ_HANDLED;
}
static struct file_operations fops ={ .owner=THIS_MODULE,.read=my_read,.write=my_write};
static int __init my_init(void)
{
	pr_info("In init\n");
	int ret=alloc_chrdev_region(&my_dev,0,1,DEVICE_NAME);
	if(ret<0)
	{
		pr_info("Couldn't able to create major and minor numbers\n");
		return ret;
	}
	pr_info("major:%d minor:%d\n",MAJOR(my_dev),MINOR(my_dev));
	cdev_init(&my_cdev,&fops);
	ret=cdev_add(&my_cdev,my_dev,1);
	if(ret<0)
	{
		pr_info("cdev failed\n");
		unregister_chrdev_region(my_dev,1);

		return ret;
	}
	my_class=class_create(DEVICE_NAME);
	if(IS_ERR(my_class))
	{
		pr_info("failed to create class\n");
		ret=PTR_ERR(my_class);
		cdev_del(&my_cdev);
		unregister_chrdev_region(my_dev,1);
		return ret;
	
	}
	my_device=device_create(my_class,NULL,my_dev,NULL,CLASS_NAME);
	if(IS_ERR(my_device))
	{
		pr_info("failed to create device\n");
		return ret;
	}

	// Interrupt handling
	ret = request_irq(IRQ_NUM,my_isr,IRQF_SHARED,DEVICE_NAME,(void*)my_isr);
	
	if(ret<0)
	{
		pr_info("Failed to allocate irq number\n");
		return ret;
	}
	
	ret = request_irq(IRQ_NUM,my_isr1,IRQF_SHARED,DEVICE_NAME,(void*)my_isr);
	
	if(ret<0)
	{
		pr_info("Failed to allocate irq number\n");
		return ret;
	}
	ret = request_irq(IRQ_NUM,my_isr2,IRQF_SHARED,DEVICE_NAME,(void*)my_isr);
	
	if(ret<0)
	{
		pr_info("Failed to allocate irq number\n");
		return ret;
	}
	pr_info("%s: IRQ :%d registered successfully\n",DEVICE_NAME,IRQ_NUM);
	

	return 0;
}
static void __exit my_exit(void)
{
	free_irq(IRQ_NUM,(void*)my_isr);
	pr_info("Freed IRQ:%d\n",IRQ_NUM);
	pr_info("In exit\n");
	unregister_chrdev_region(my_dev,1);
	kfree(ptr);
	device_destroy(my_class,my_dev);
	cdev_del(&my_cdev);
	class_destroy(my_class);
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Written by unseen author");
MODULE_AUTHOR("Unseen Author");
module_init(my_init);
module_exit(my_exit);
