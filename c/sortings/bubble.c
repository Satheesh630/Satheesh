#include<stdio.h>
void bubble_sort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int swapped=0;
		for(int j=0;j	<n-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swapped=1;
			}
		}
		if(!swapped)
		 break;
	}
}
., 
int main()
{
	int arr[]={6,3,5,2,34,5,2,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k;
	printf("Enter N th largest numbet\n");
	scanf("%d",&k);
	bubble_sort(arr,n);
	if(k<=n)
	printf("%d\n",arr[k-1]);
	else
	printf("Enter in valid range\n");
	/*for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
		printf("\n");*/
}
