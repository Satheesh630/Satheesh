#include<iostream>
#include<cstring>
using namespace std;
class shallow
{
	char *p;
	public:
	shallow(const char *s)
	{
		p=new char[strlen(s)+1];
		strcpy(p,s);
	}
	void show()
	{
		cout<<p<<endl;
	}
	void modify(int index)
	{
		p[index]='S';
	}
};
int main()
{
	shallow obj1("vector"),obj2(obj1);
	obj1.show();
	obj2.modify(0);
	obj1.show();

}
