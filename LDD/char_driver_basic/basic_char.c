#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/fs.h>

#define DEVICE_NAME "Basic_char"


static void *ptr;
static int major;
static int my_open(struct inode *inode , struct file *file)
{
	printk("Hey file opened\n");
	return 0;
}
static int my_release(struct inode *inode, struct file *file)
{
	pr_info("Hello Closing File\n");
	return 0;
}	
static ssize_t my_read(struct file *file, char __user *user_buffer, size_t count,loff_t *offset)
{
	copy_to_user(user_buffer,ptr,count);
	return 0;
}	
static void change(char *ptr)
{
	int i=0;
	while(ptr[i])
	{
		if((ptr[i] >='a') && (ptr[i] <='z'))
			ptr[i] -=32;
		else if(ptr[i] >='A' && ptr[i] <= 'Z')
			ptr[i]+=32;
	i++;
	}
}
static ssize_t my_write(struct file *file,char __user *user_buffer,size_t count,loff_t *offset)
{
	ptr=kmalloc(100,GFP_KERNEL);
	if(!ptr)
	{
		pr_info("Kernel memory creation filed\n");
		return -ENOMEM;
	}
	copy_from_user(ptr,user_buffer,count);
	change(ptr);
}
static struct file_operations fops={.owner=THIS_MODULE,.open=my_open,.release=my_release,.read=my_read,.write=my_write,};
static int __init my_init(void)
{
	major=register_chrdev(0,DEVICE_NAME,&fops);
	if(!major)
	{
		pr_err("failed to register char driver\n");
		return -1;
	}
	pr_info("Hello In my init majot-%d\n",major);
	return 0;
	
}	
static void __exit  my_exit(void)
{
	kfree(ptr);	
	unregister_chrdev(major,DEVICE_NAME);
	
	pr_info("Hello Im in exit\n");
}



module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Satheesh");
MODULE_DESCRIPTION("Basic char driver");
MODULE_LICENSE("GPL");



