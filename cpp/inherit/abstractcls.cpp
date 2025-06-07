#include<iostream>
//A class containing atleast one pure Virtual function called abstract class.
using namespace std;
class a
{
	public:
	virtual void fun()=0;
};
class b:public a
{
	public:
	void z()
	{
		cout<<"In s"<<endl;
	}
	void fun()
	{
		cout<<"In virtual class"<<endl;
	}
};
class c:public b
{
	public:
	c()
	{
		cout<<"Constructor"<<endl;
	}
}; 
int main()
{
		c obj;
		obj.fun();

}
