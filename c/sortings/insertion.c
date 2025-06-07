#include<stdio.h>
void insertion(int arr[],int n)
{
	int j,key;
	for(int i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}	
 }

int main()
{
	int arr[]={64,25,12,22,11};
	insertion(arr,5);
		for(int i=0;i<5;i++)
	printf("%d ",arr[i]);
	printf("\n");
	
}
