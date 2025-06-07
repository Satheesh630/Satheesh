#include<iostream>
using namespace std;
template<class type>
type sum(type a,type b)
{
	cout<<typeid(a).name()<<endl;
	return a+b;
}
int main()
{
	int a=sum(1,2);
	cout<<a<<endl;
}
