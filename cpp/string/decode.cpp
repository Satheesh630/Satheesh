#include<bits/stdc++.h>
using namespace std;
void decode(string s)
{
	stack<int> numstack;
	stack<string> strstack;
	string cur="";
	int num=0;//3[a]
	for(int i=0;i<s.length();i++)
	{
		if(isdigit(s[i]))
		{
			
			while(isdigit(s[i]))
			{
				num=num*10+(s[i]-'0');
				i++;
			}
			
		}
		if(s[i]=='[')
		{
			numstack.push(num);
			strstack.push(cur);
			num=0;
			cur="";
		}
		else if (s[i]==']')
		{
			int r=numstack.top();
			numstack.pop();
			string tmp;
			tmp=cur;
			cur=strstack.top();
			strstack.pop();
			while(r--)
				cur+=tmp;
				
		}
		else
		{
			cur+=s[i];
		}
	}
	
	cout<<cur<<endl;
	
}
int main()
{
	string s;
	cout<<"Enter string:";
	getline(cin,s);
	decode(s);
}
