#include<stdio.h>
void merge(int arr[],int left,int mid,int right)
{
	int n1=mid-left+1;
	int n2=right-mid;

	int temp1[n1],temp2[n2];
	for(int i=0;i<n1;i++)
		temp1[i]=arr[left+i];
	for(int j=0;j<n2;j++)
		temp2[j]=arr[mid+1+j];
	int i=0,j=0,k=left;
	while(i< n1 && j<n2 )
	{
		if(temp1[i] <= temp2[j])
		{
			arr[k++]=temp1[i++];
		}else
			arr[k++]=temp2[j++];
	}	
	while(i<n1)
		arr[k++]=temp1[i++];
	while(j<n2)
		arr[k++]=temp2[j++];
	
	

}
void merge_sort(int arr[],int left, int right )
{
	if(left>=right)
		return ;
	int mid=left+(right-left)/2;
	merge_sort(arr,left,mid);
	merge_sort(arr,mid+1,right);
	merge(arr,left,mid,right);
}
int main()
{
	int arr[]={3,1,4,5,2,5};
	merge_sort(arr,0,5);
	for(int i=0;i<6;i++)
		printf("%d ",arr[i]);
		printf("\n");

}
