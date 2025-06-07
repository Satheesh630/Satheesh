#include<iostream>
using namespace std;
void insertion(int arr[],int size)
{
if(size==0)
return;


	int key,j;
	for(int i=1;i<size;i++)
	{
		int key=arr[i];
		j=i-1;
		while(j>=0 && arr[j] >key)
		{
			swap(arr[j],arr[j+1]);
			j--;
		}
		arr[j+1]=key;
	}
}
int main()
{
	int arr[5];
	printf("Enter elements\n");
	for(int i=0;i<5;i++)
		scanf("%d",&arr[i]);
	int size=5;
	insertion(arr,size);
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
}
