#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[]={1,2,3,4,5};
	char *ptr=arr,*ptr1=&arr+1;
	int a = (ptr1-ptr)/4;
	printf("%d\n",a);
}
