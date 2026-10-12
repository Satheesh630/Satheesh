// Find kth largest element in a given int array 
#include<stdio.h>
int find_kth(int *arr,int k)
{
	int heap[k]={0};
	
}
int main()
{
	int ele,k;
	printf("Enter number of elements\n");
	scanf("%d",&ele);
	printf("Enter array elements\n");
	int arr[ele];
	for(int i=0;i<ele;i++)
		scanf("%d",&arr[i]);
	
	printf("Enter which largest element to find\n");
	scanf("%d",&k);
	int ret=find_kth(arr,k);
	printf("%d 'th largest element :%d\n",k,ret);
}
