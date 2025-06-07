#include<stdio.h>
int rev(int);
void main()
{
int num=rev(1234);
printf("%d\n",num);
}
int rev(int num)
{
static int rev=0;
if(num==0)
return rev;

rev=(rev*10)+(num%10);
return rev(num/10)

}
