#include<stdio.h>
void fibonacci()
{
	int start,end;
	printf("Enter startin and ending\n");
	scanf("%d%d",&start,&end);
	if(start<0)
	{
		printf("No negative numbers allowedn\n ");
		return;	
	}
	if(end==0)
	{
		printf("Enter valid range\n");
		return;
	}
	if(start>end)
	{
		printf("Invalid Range\n");
		return;
	}
	int i=0,j=1;
	printf("%d %d ",i,j);
	int new=i+j;
	if(end==1)
	return;
	
	for(;new<end;new=i+j)
	{
		printf("%d ",new);
		i=j;
		j=new;
	}
	printf("\n");
}
void main()
{
	fibonacci();

}














