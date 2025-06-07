#include<iostream>
using namespace std;
class A
{
	int a,b,c;
	friend void fun();
	//friend void display();
};
class b
{
	int cash=100,gold=700;
	void fun(A&ref)
	{
		cout<<"In class b"<<ref.a<<endl;
	}
};
void fun()
{
	a=10;
	b=10;
	c=10;
}

int main()
{
	A obj;
	fun();
//	display();
	

}
