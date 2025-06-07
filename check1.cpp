#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
	vector<int> m;
	int n;
	for(int i=0;i<5;i++)
		{
			cin>>n;
			m.push_back(n);
		}
	set<int,greater<int>> get(m.begin(),m.end());
	
	if(get.size()<0)
		cout<<EOF<<endl;
	else
	{
		auto it=get.begin();
		cout<<*++it<<endl;
	}
}
