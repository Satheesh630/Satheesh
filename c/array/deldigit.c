#include<stdio.h>
void main()
{
int num=12342,r,result=0,mul=1,digit=3;
while(num)
{
r=num%10;
if(r!=digit)
{
result=result+r*mul;
mul=mul*10;
}
num=num/10;
}



printf("%d \n",result);





}

