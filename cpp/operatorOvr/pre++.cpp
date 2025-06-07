#include<iostream>
using namespace std;
class A
{
	int a,b;
	public:
	A(int a=0,int b=0):a(a),b(b){}
	A operator++()
	{			//pre increment
	cout<<"pre increment called"<<endl;
		A tmp;
		tmp.a=++a;
		tmp.b=++b;
		return tmp;
	}
	A operator++(int)
	{
	cout<<"post increment called"<<endl;
		A tmp;
		tmp.a=a++;
		
		tmp.b=b++;
		return tmp;
	}
	void get_data()
	{
		cout<<a<<" "<<b<<endl;
	}
};

int main()
{
	A obj,obj1;
	obj1=obj++;//obj1.operator++(0);
	//obj1=++obj;   obj1.operator++();
	obj1.get_data();
	obj.get_data();
	
}
