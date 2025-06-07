#include"header.h"
class A
{

public:
	
	
	int b;
	int c;
	
	static int a ;
	A():b(10),c(30){}

	void oc()
	{
		cout<<"Count :"<<a<<endl;
	}
	static void func()
	{
	
		cout<<"this is in statict func"<<endl;
		cout<<"a="<<a<<"b="<<b<<endl;
	}
	~A()
	{
	--a;
	}
	
};
int A::a;	
int main()
{
	A::func();
}
