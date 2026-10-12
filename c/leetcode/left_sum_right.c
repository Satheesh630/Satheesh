#include<stdio.h>
int find_midindex(int *arr,int n)
{
	int rsum=0,lsum=0;
	int i=-1,j=n;
	while(i != j)
	{
		if(lsum < rsum)
		{
			lsum+=arr[++i];
		}else if(rsum<lsum)
		{
			rsum+=arr[--j];
		}else if(lsum==rsum)
		{
			lsum+=arr[++i];
			rsum += arr[--j];
		}
	}
	if(lsum==rsum)
		return i;
	else
		return -1;
}	
int main()
{
	int n;
	printf("Eneter no of elements\n");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int index=find_midindex(arr,n);
	printf("index:%d\n",index);
}
