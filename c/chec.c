#include<stdio.h>
void fun(int *p)
{
int i=10;
*p=10;

}
void main()
{
int i=0;
fun(&i);
printf("%d\n",i);

}
