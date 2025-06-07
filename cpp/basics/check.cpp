#include<iostream>
using namespace std;
void check(string& s,string& sml)
{
	int l=0,max=2000,i=0,j=0;
	string tmp;
	while(s[j])
	{
	
		if(isspace(s[i]) || s[i]==0)
		{
			if(l<max)
			{
				sml=tmp;
				i=0;
				l=0;
			}
			j++;
			tmp.clear();
			
			
		}
		else
		{
			tmp[i++]=s[j++];
			l++;
			
		}
	}
}

int main()
{
	string s;
	cout<<"Enter a string"<<endl;
	getline(cin,s);
	string small(20,'0');
	check(s,small);
	//cout<<s<<endl;
	cout<<small<<endl;	
}
