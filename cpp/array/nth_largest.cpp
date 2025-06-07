#include<iostream>
#include<algorithm>
using namespace std;
void bubble(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int swapped=0;
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				swapped=1;
			}	
		}
		if(!swapped)
			break;
	}
}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
		printf("\n");
}	
int main()
{

}
