#include<iostream>
#include<cstring>
//Through friend fun [] can't be overloaded
using namespace std;
class A
{
	char *s;int size;
public:
	A(const char *ptr)
	{
		
		s=new char[strlen(ptr)+1];
		strcpy(s,ptr);
		size=strlen(s);
	}
	char& operator[](int i)
	{
		return this->s[i];
	}
	
	void display()
	{
		cout<<s<<endl;
	}
};

int main()
{
	A obj("Satheesh");                    
	cout<<obj[1]<<endl;			//obj.operator[](&obj,1);
	obj[1]='Z';
	obj.display();
}
