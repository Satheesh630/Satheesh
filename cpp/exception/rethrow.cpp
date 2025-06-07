#include<iostream>
using namespace std;
void user()
{
	throw "n/w issue";
}
void care()
{
	try
	{
		user();
	}catch(const char *s)
	{
		cout<<"In care exception"<<s<<endl;
		throw;
	}
}
int main()
{
	try
	{
		care();
	}
	catch(const char *s)
	{
		cout<<"In main exception"<<s<<endl;
	}
}
