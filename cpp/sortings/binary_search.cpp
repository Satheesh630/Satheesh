#include<iostream>
#include<algorithm>
using namespace std;
int  binary(int arr[],int lb,int ub,int target)
{
	if(lb<=ub)
	{
		int mid=lb+(ub-lb)/2;
		if(arr[mid]==target)
			return mid;
		else if(target<arr[mid])
			return binary(arr,lb,mid-1,target);
		else if(target >arr[mid])
		  return binary(arr,mid+1,ub,target);
	}
	return EOF;

}
int main()
{
	int arr[]={1,2,3,4,5,6};
	int n;
	cout<<"Enter a number to search"<<endl;
	cin>>n;
	int ind=binary(arr,0,5,n);
	if(ind==EOF)
		cout<<"Given Number is not present  int the rang"<<endl;
	else
	cout<<"Given number present in "<< ind<<" location "<<"That is "<<arr[ind]<<endl;
}
