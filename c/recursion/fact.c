#include<stdio.h>
int fact(int);
void main()
{
int n,num;
printf("Enter number \n");
scanf("%d",&n);
num=fact(n);
printf("%d \n",num);
}
int fact (int num)
{
if(num)
return num*fact(num-1);
else 
return 1;


}
