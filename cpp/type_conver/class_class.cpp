#include<iostream>
using namespace std;
class A
{
		int i,j;
		public:
		A():i(0),j(0){}
		A(int a,int b)
		{
			i=a,j=b;
		}
		void get_data()
		{	
			cout<<i<<endl<<j<<endl;
		}
};
class   B 
{
	int m,n;
	public:
	B():m(10),n(20){}
	operator A()
	{
		return A(m,n);
	}
	
	
};
int main()
{
	A a1;
	B b1;//b==s a==target
	a1=b1;
	a1.get_data();
	
}
