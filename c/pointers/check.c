#include<stdio.h>
void main()
{
int i=10,*p;
p=&i;
int j=*p++;;
printf("&p=%p\n",p);
printf("*p=%d\n",*p);
printf("j=%d\n",j);
}
