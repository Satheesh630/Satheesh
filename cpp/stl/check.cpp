#include<iostream>
#include<iomanip>
#include<set>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main()
{
	vector<int> v={1,2,1,2,1,2,3,2,4,2,4,3,3};
	set<int,greater<int> > s(v.begin(),v.end());
	
		
	
	for(auto a:s)
		cout<<a<<" ";
		cout<<endl;
	
}











