#include<iostream>
using namespace std;
void selection_sort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
				swap(arr[i],arr[j]);
		}
	}
}
int main()
{
	int arr[10];
	cout<<"enter arry elements"<<endl;
	for(int i=0;i<10;i++)
		cin>>arr[i];
	selection_sort(arr,10);
	for(int i=0;i<10;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
}
