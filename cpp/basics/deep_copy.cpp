#include"header.h"
class deep
{
	char *p;
	public:
	deep():p(0){}
	deep(const char *s)
	{
		p=new char[strlen(s)+1];
		strcpy(p,s);
	}
	deep(deep &obj)
	{
		p=new char[strlen(obj.p)+1];
		strcpy(p,obj.p);
	}
	void show()
	{
		cout<<p<<endl;
	}
	void modify()
	{
		p[0]='S';
	}
};
int main()
{
	deep obj("vector"),obj1(obj);
	cout<<"In obj  ";obj.show();
	cout<<"in obj1 ";obj1.show();
	obj1.modify();
	cout<<"In obj ";obj.show();
	cout<<"In obj1 ";obj1.show();
}
