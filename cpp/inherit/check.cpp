#include<iostream>
using namespace std;
class a
{
	public:
	virtual void fun()
	{
		cout<<"func in a"<<endl;
	}
};
class b:public a
{
	public:
	void fun ()
	{
		cout<<"fun in b"<<endl;		
	}
};
int main()
{
	cout<<sizeof(a)<<endl;
	cout<<sizeof(b)<<endl;
}
