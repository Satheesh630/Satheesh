#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Panic check");
MODULE_AUTHOR("Satheesh Panicker");

int __init my_init(void)
{
	pr_info("In init\n");
	int *ptr=NULL;
	pr_info("%d \n",*ptr);
	return 0;
}
void __exit my_exit(void)

{
	pr_info("In Exit\n");
}
module_init(my_init);
module_exit(my_exit);

