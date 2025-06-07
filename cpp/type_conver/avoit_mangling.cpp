#include<iostream>
using namespace std;
extern "C"
{
	void print()
	{
		cout<<"Hello Kate"<<endl;
	}
}
int main()
{
	print();
}
