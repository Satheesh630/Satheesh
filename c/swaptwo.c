#include<stdio.h>
void main()
{
int num=1234,r,q,l,i;
/*i=num%10;//4
num=num/10;
j=num%10;//3
num=num/10;
k=num%10;//2
l=num/10;//1
num=i*10+j;
num=num*10+k;
num=num*10+l;
printf("i=%d j=%d k=%d l=%d num=%d \n",i,j,k,l,num);
//printf("Swapped number is  %d \n",a);

*/
for(int i=0;i<=4;i++)
{
r=num%10;
l=num/10%10;
num=r*10+l;
}
printf("NUMBER = %d ",num);
}
