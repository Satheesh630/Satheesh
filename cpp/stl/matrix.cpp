#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int>> matrix(3,vector<int>(3,100));
	for(int i=0;i<3;i++){
		for(int j=0;j <3;j++)
			cout<<matrix[i][j]<<" ";
			cout<<endl;
			}
			
			
}
