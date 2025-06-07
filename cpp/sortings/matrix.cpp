#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
void print(vector<vector<int>> matrix)
{
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void reverse_rows(vector<vector<int>> matrix)
{
	for(auto row=matrix.begin();row!=matrix.end();++row)
	{
		reverse(row->begin(),row->end());
	}
	print(matrix);
}
void reverse_cols(vector<vector<int>> matrix)
{
	int r=matrix.size(),c=matrix[0].size();
	for(int col=0;col<c;++col)
	{
		int top=0;
		int bottom=r-1;
		while(top<bottom)
		{
			swap(matrix[top][col],matrix[bottom][col]);
			top++;
			bottom--;
		}
	}
	print(matrix);
}
void transpose(vector<vector<int>> &matrix)
{
	int row=matrix.size(),col=matrix[0].size();
	for(int i=0;i<row;++i)
	{
		for(int j=i+1;j<col;++j)
			swap(matrix[i][j],matrix[j][i]);
	}
	print(matrix);
}
void rotate_90(vector<vector<int>> matrix)
{
	transpose(matrix);
	reverse_rows(matrix);
	print(matrix);
}
void rotate_180(vector<vector<int>> matrix)
{
	reverse_rows(matrix);
	reverse_cols(matrix);
	print(matrix);
}
void rotate_270(vector<vector<int>> matrix)
{
	transpose(matrix);
	reverse_cols(matrix);
	print(matrix);
	
}
int main()
{
	int r=3,c=3;
//	cout<<"Enter number of rows and columns"<<endl;
//	cin>>r>>c;
	vector<vector<int>> matrix(r,vector<int>(c));
	/*for(int i=0;i<r;i++)
		{
			int val;
			for(int j=0;j<c;j++)
				{
				cin>>val;
				matrix[i][j]=val;
				}
		}*/
		matrix[0]={1,2,3};
		matrix[1]={4,5,6};
		matrix[2]={7,8,9};
	reverse_rows(matrix);
	reverse_cols(matrix);
	transpose(matrix);
	rotate_90(matrix);
	rotate_180(matrix);
	rotate_270(matrix);

}


