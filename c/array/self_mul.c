#include<stdio.h>
void main()
{
int a[]={1,2,3,4},i,mul,j;
int temp[]={1,2,3,4};
for(i=0;i<4;i++)
{
mul=1;
for(j=0;j<4;j++)
{
if(i!=j)
mul=mul*temp[j];
}
a[i]=mul;
}
for(i=0;i<4;i++)
printf("%d\n",a[i]);




}
