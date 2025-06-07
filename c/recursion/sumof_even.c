
#include<stdio.h>
int sum(int );
void main()
{
int i=sum(1233456);
printf("sum=%d\n",i);

}
int sum(int num)
{
if(num==0)
return 0;
int r=num%10;
if(r%2==0)
return r+sum(num/10);
else
return sum(num/10);

}
