#include<iostream>
using namespace std;
class A
{
	int a ,b;
	public:
	A(){}
	A operator+(A tmp);
	A operator=(A v);
	A(int a,int b):a(a),b(b){}
	void get_data()
	{
		cout<<"a="<<a<<"b="<<b<<endl;
	}
};
int main()
{
	A obj(1,2),obj2(obj),obj1=obj+obj2;
	obj1.get_data();
	obj=obj1;;
	obj1.get_data();
}

A operator=(A v,A v1)
{
	v.a=v1.a
	v.b=v1.b;
	return v;
}

A A::operator=(A v)
{
	a=v.a;
	b=v.b;
	return *this;
}
A A::operator +(A tmp)
{
	A v;
	v.a=tmp.a+a;
	v.b=tmp.b+b;
	return v;
}
