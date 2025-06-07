#include<iostream>
using namespace std;
void Bubble_sort( int *arr,int n)
{

	for(int i=0;i<n-1;i++)
	{
	bool swapped=false;
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				swapped=true;
			}
			if(!swapped)
			break;
		}
	}
}
int main()
{
	int arr[]={30,20,40,60,80};
	Bubble_sort(arr,5);
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
