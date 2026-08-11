#include<stdio.h>
void merge(int arr[],int l,int m,int r)
{
	int n1,n2;
	n1=m-l+1;
	n2=r-(m+1)+1;
	int temp1[n1],temp[n2];
	for(int i=0;i<
}
static void mergesort(int arr[],int l,int r)
{
	if(!(l<r))
		return;
	int mid=l+(r-l)/2;
	mergesort(arr,l,mid);
	mergesort(arr,mid+1,r);
	merge(arr,l,m,r);

}
int main()
{
	int arr[]={4,2,4,8,6,3,0};
	mergesort(arr,0,7);
	for(int i=0;i<7;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
