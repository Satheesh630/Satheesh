/*
	1.set_terminate();
	2.Terminate call
	3.
*/
#include<iostream>
using namespace std;
void emergency()
{
	cout<<"Emergency call"<<endl;
	cerr<<"unhandled Exception"<<endl;
	abort();
}
int main()
{
	set_terminate(emergency);
	try
	{
		throw 13.2;
	}
	catch(int a)
	{
	cout<<"Int"<<a<<endl;
	}
	catch(float f)
	{
		cout<<"Float f"<<f<<endl;
	}
	

}
