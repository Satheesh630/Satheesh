#include"header.h"
class A
{
	int cash,gold;
	public:
	A():cash(010),gold(020){}
	void show()
	{
		cout<<cash<<" "<<gold<<endl;
	}
	void modify() const
	{
		cout<<"In const mem fun()"<<endl;
		cout<<cash<<" "<<gold<<endl;
	}
};
int main()
{
	const A obj;
	obj.show();
	obj.modify();
}	
