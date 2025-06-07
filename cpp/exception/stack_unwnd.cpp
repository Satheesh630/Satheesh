#include<iostream>
using namespace std;
	 void test3()
	 {
	 	cout<<"In test3 fun"<<endl;
	 	throw "hello";
	 }
	 void test2()
	 {
	 	test3();
	 	cout<<"In test2"<<endl;
	 }
	 void test1()
	 {
	 	test2();
	 	cout<<"In test 1"<<endl;
	 }

void rec(int a)
{
	if(a<3)
	{
		rec(a+1);
	}
	
	cout<<"After if "<<a<<endl;
//throw a;
}
int main()
{
	try
	{
		rec(0);
		cout<<"In main()"<<endl;
	}
	catch(int n)
	{
		cout<<n<<endl;
	}
}
