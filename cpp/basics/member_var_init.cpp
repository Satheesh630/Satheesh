#include<iostream>
using namespace std;
class A
{
	const int a,b;
	public:
	int fun();
	A():a(10),b(20){}
friend int main();
};
int main()
{
	A ob;
	cout<<ob.a<<" "<<ob.b<<endl;
	
}
int A::fun()
{
	return 10;
}
