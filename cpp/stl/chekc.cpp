#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	vector<int> v={1,2,3,4,4,5,5,6,2};
	vector <int> v1;
	
	copy_if(v.begin(),v.end(),back_inserter(v1),[](int i){ return i%2 != 0;});
	
	for(auto i:v1)
		cout<<i<<" ";
		cout<<endl;
} 
