#include<iostream>
#include<iomanip>
#include<locale>
using namespace std;
class A
{
	public:
	A()
	{
		cout<<"In  class A"<<endl;
	}
};
class B:public A
{
	public:
		B()
		{
			cout<<"In class B"<<endl;
		}
};
int main()
{
	B obj;
}
