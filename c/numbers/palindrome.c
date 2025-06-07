#include<stdio.h>
void palin()
{
	int start,end;
	printf("Enter starring and ending\n");
	scanf("%d%d",&start,&end);
	int tmp,sum=0,mul=1,r;
	
	for(;start<=end;start++)
	{
	sum=0;mul=1;
	tmp=start;
	while(tmp)
	{
		r=tmp%10;
		sum=sum*mul+r;
		mul=10;
		tmp/=10;
	}
		if(sum==start)
		printf("%d ",sum);
	}


	printf("\n");
	
}
void main()
{
	palin();

}
