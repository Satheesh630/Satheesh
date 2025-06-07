/* 
		It is can only overloaded by member function
		= is already overloaded in compiler 
		if we overload using friend there will be ambiguity issue i.e compiler dont know 
		whether to use the default one or defined in friend function */
#include<iostream>
using namespace std;
class A
{	
	int a,b;
	public:
	A(){}
	A(int s=0,int x=0):a(s),b(x){}//works as default constructor as well as  parameterized constructor
	
/*	A& operator=(const A& var)
	{
		if(this !=&var)
		{
			a=var.a;
			b=var.b;
		}
		return *this;	#  *this gives a variable where this is a pointer.
	
	}
	*/
	A operator =(const A var)
	{
		a=var.a;
		b=var.b;
		return *this;
	}
	void display()
	{
		cout<<"a= "<<a<<" " <<"b "<<b<<endl;
	}

};
int main()
{
	A a,b(30,40),c(40,50);
	a.display();
	a=b=c;
	a.display();
}
