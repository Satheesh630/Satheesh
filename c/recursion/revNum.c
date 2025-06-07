#include<stdio.h>
int perfect(int);
void main()
{
if(perfect(7))
printf("Perfect\n");
else printf("Not perfect\n");

}
int perfect(int num)
{
if(num==0)
return 0;
static int sum=0,i=0;
i++;
if(num==sum)
return 1;

if(i<=num/2)
{
if((num%i)==0)
{
sum=sum+i;
perfect(num);

}
}else return 0;



}
