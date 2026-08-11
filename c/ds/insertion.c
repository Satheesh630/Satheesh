#include<stdio.h>
void sortInsrt(int arr[],int n)
{
	if(n==1)
	return ;
	int i=1,j=0,temp=0;
	while(i<n)
	{
		j=i-1;
		temp=arr[i];
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
		i++;
	}
}
int main()
{
	int arr[6];
	for(int i=0;i<6;i++)
		scanf("%d",&arr[i]);
	sortInsrt(arr,6);
	for(int i=0;i<6;i++)
		printf("%d ",arr[i]);
	
}
