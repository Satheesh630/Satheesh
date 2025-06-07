#include <iostream>
using namespace std;
int main()
{
	int r,c;
	cout<<"Enter number of rows and columns"<<endl;
	cin>>r>>c;
	int **matrix= new int*[r];
	for(int i=0;i<r;i++)
	matrix[i]=new int[c];

	cout<<"Enter array elements"<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;i<c;j++)
			cin>>matrix[i][j];
	}
			
		for(int i=0;i<r;i++)
		for(int j=0;i<c;j++)
			cout<<matrix[i][j];			
}

