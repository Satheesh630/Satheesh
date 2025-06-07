#include<stdio.h>
void perfect()
{
	int start,end;
	printf("Enter starting and ending\n");
	scanf("%d%d",&start,&end);
	int sum;
	for(;start<=end;start++)
	{
	sum=0;
		for(int i=1;i<start;i++)
		{
			if((start%i)==0)
			{
				sum=sum+i;
			}
		}
		if(sum==start)
			printf("%d ",sum);
	}
	printf("\n");
}
void strong()
{
	int start,end,r,fact=1,tmp,sum=0;
	printf("Enter starting and ending\n");
	scanf("%d%d",&start,&end);
	for(;start<=end;start++)
	{
	fact=1;
	tmp=start;
	sum=0;
	while(tmp)
	{
		r=tmp%10;
			while(r)
		    fact=fact*(r--);
		    sum=sum+fact;
		tmp/=10;
	}
	if(start==sum)
		printf("%d ",fact);
	}
printf("\n");	

}
void main()
{
	strong();
}
