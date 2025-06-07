#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int row,column;
	cin>>row>>column;
	vector<vector<int>> matrix(row,vector<int>(column,0));
	for(int i=0;i<row;i++)
		for(int k=0;k<column;k++)
		cin>>matrix[i][k];
	vector<vector<int>> tran(column,vector<int>(row,0));
	for(int i=0;i<column;i++)
	{
		for(int j=0;j<row;j++)
			tran[i][j]=matrix[j][i];
	}
	for(int i=0;i<column;i++)
	{
		for(int j=0;j<row;j++)
		cout<<tran[i][j]<<" ";
		cout<<endl;
	}
}
