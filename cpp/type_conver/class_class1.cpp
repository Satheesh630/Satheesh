#include<iostream>
using namespace std;
class B;
class B
{
	int m,n;
	public:
		B():m(20),n(30){}
		
		int get_m()
		{
			return m;
		}
		int get_n()
		{
			return n;
		}
};
class A
{
	int a,b;
	public:
		A():a(0),b(0){}
		A(B tmp)
		{
			a=tmp.get_m();
			b=tmp.get_n();
		}
		void show()
		{
			cout<<a<<endl<<b<<endl;
		}
};

int main()
{
		B obj;
		A obj1;
	obj1=obj;
	obj1.show();
}
