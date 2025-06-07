#include<stdio.h>
int sum(int);
void main()
{
int i=sum(1234567890);
printf("SUM=%d\n",i);


}
int sum(int num)
{
if(num)
return num%10+sum(num/10);
}
