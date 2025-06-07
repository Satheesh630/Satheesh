#include<iostream>
using namespace std;
void swap(int *p,int *q)
{
	int temp=*p;
	*p=*q;
	*q=temp;
}
int partician(int arr[],int lb,int ub)
{
	int pivot,start,end;
	start=lb,end=ub,pivot=arr[lb];
	
	while(start<end)
	{
	while(arr[start] <= pivot)
		start++;
	while(arr[end]>pivot)
		end--;
	if(start < end)
		swap(&arr[start],&arr[end]);
	}
	swap(&arr[lb],&arr[end]);
	return end;
}
void quicksort(int arr[],int lb,int ub)
{
	if(lb<ub)
	{
		int mid=partician(arr,lb,ub);
		quicksort(arr,lb,mid-1);
		quicksort(arr,mid+1,ub);
	}
}
int main()
{
	int arr[5];
	printf("Enter array elements\n");
	for(int i=0;i<5;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,5-1);
	
	for(int i=0;i<5;i++)
		printf("%d ",arr[i]);
	printf("\n");
}












