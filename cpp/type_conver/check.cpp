#include<iostream>
using namespace std;
extern "C"
{
	void print()
	{
		cout<<"In extern"<<endl;
	}
}
int main()
{
	print();
}
