#include<stdio.h>
int factf(int);
void   main()
{
	
int num,r,sum=0,temp,fact;
for(num=1;num<1000;num++)
{
//	printf("Enter a number \n");
//	scanf("%d",&num);
	temp=num;
	while(num>0)
	{
		r=num%10;
		fact=factf(r);
		sum=sum+fact;
		num=num/10;
	}
	if(sum==temp)
		printf("%d \n",sum);
}}
int factf(int r)
{
int fact=1;
for(int i=1;i<=r;i++)
fact=fact*i;
return fact;

}


/*

\\\\\\Own method

	int num,i,fact,r,sum=0,temp;
	printf("Enter a number \n");
	scanf("%d",&num);
	temp=num;
	while(num>0)
	{
		r=num%10;
		fact=1;
		for(i=1;i<=r;i++)
			fact=fact*i;
		sum=sum+fact;
		num=num/10;
	}
	if(sum==temp)
		printf("Given number is a Strong number \n");
	else 
		printf("Not a Strong number \n");
*/

