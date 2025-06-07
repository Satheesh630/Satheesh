#include<stdio.h>
#include<stdlib.h>
int fun(const void* a, const void *b)
{
	return *((int *a) - *((int *)b);
}
int main()
{
	int n=3;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	} 
	qsort(arr,3,sizeof(int),fun);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	} 
}
