#include<stdio.h>
struct max
{
	int lefti,righti;
};
struct max max_diff(int *arr,int n)
{
	int i=0,j=1,mxdiff=0;
	struct max obj={0,0};
	if(n<2)
		return obj;
	for(;j<n;)
	{
		int diff=arr[i]-arr[j];
		if(diff > mxdiff)
		{
			mxdiff=diff;
			j++;
			obj.lefti=i;
			obj.righti=j;
		}else if(diff <mxdiff)
		{
			i=j;
			j=j+1;
		}
	}
	return obj;
}
int main()
{
	int n;
	printf("Eneter no of elements\n");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	struct max obj=max_diff(arr,n);
	printf("index:%d %d\n",obj.lefti,obj.righti);

}
