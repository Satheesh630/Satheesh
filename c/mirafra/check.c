#include<stdio.h>
int main()
{
	char *ptr="Hello World";
	char **ptr1=&ptr;
	*ptr1[0]='h';
	printf("%s\n",ptr);
}
