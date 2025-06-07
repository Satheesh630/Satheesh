#include<iostream>
using namespace std;
class A
{
	int a,b;
	public:
	A(int a=10,int b=20):a(a),b(b){}
	void get_data()
	{
		cout<<a<<" "<<b<<endl;
	}

};
class smart_ptr
{
	A *ptr;
	public:
	smart_ptr()
	{
		ptr=new A;
	}
	A* operator ->()
	{
		return ptr;
	}
	A operator *()
	{
		return *ptr;
	}	
	~smart_ptr()
	{
		delete ptr;
	}
};
int main()
{
	smart_ptr p1,p2;
	(*p1).get_data();
}
/* It is a pointer class designed for holding a perticular class object address
when we create the object of this class memorey is dynamically allocated for the perticular 
class 
All the pointer related are overloaded within this class*/
 
