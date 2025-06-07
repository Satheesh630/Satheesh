#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[],int st,int mid,int end)
{
	int n1,n2;
	n1=mid-st+1;
	n2=end-st;
	vector<int> left(n1),right(n2);
	for(int i=0;i<n1;i++)
		left[i]=arr[st+i];
	for(int i=0;i<n2;i++)
		right[i]=arr[mid+1+i];
		
	int i=0,j=0,k=st;
	
	while(i<n1 && j<n2)
	{
		if(left[i] < right[j])
		{
			arr[k]=left[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=right[j];
			j++;k++;
		}
	}
	while(i<n1)
	{
		arr[k]=left[i];
		i++;k++;
	}
	while(j<n2)
	{
		arr[k]=right[j];
		j++,k++;
	}
}
void mergesort(int arr[],int start,int end)
{
	if(start<end)
	{
		int mid=start+((end-start)/2);
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);	
		merge(arr,start,mid,end);
	}
}
void print(int arr[],int size)
{
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
}
int main()
{
	int arr[]={5,3,5,26,7,3,2,6,43,8};
	int size=sizeof(arr)/sizeof(arr[0]);
	mergesort(arr,0,size-1);
	print(arr,size);
}
