#include<iostream>
using namespace std;
class A
{
	int a,b;
	public:
	A(int x=0,int y=0):a(x),b(y){
	cout<<"constructor caled"<<endl;}
	void* operator new(unsigned size)//new A[10];
	{
	
	}

};
int main()
{
	
	A *ptr=new A;
}
