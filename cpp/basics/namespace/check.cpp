#include<iostream>
#include<unistd.h>
using namespace std;
class A
{
	public:
	int i=100;
	friend ostream &operator<<(ostream &out,A obj);
};
ostream & operator<<(ostream& out ,A obj)
{
	cout<<obj.i<<endl;
	return cout;
}
int main()
{
	A obj;
	cout<<obj;
}		 
