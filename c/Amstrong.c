#include<stdio.h>
void   main()
{
int num;
//	for( num=1;num<=200;num++)
	{ 
		int i,sum=0,r;
		int temp=num;
		while(num!=0)
		{
			r=num%10;
			sum=sum+(r*r*r);
			num=num/10;
		}
		if(sum==temp)
		printf("%d\n",sum);
	}
}
/*

\\\\\\won code 


	int sum=0,cube,i,num=153,r,t;
	t=num;
	for(i=0;i<310;i++)
	{
		r=num%10;
		if(num>10)
			num=num/10;
		cube=r*r*r;
		sum =sum+cube;

	}
	printf("%d\n",sum);
	if(sum==t)
		printf("It's an amstrong number\n");
	else 
		printf("Not an Amstrong number\n");
*/

