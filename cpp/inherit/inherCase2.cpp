#include<iostream>
using namespace std;
/*
	1.SINGLE INHERi:Derivation of a class from only one base class.
	2.MULTILEVEL INHERI:DErivation of a class from two or more classes.
	3.MULTIPLE INHERI:DErivation of a class from more than one class.
	4.HYBRID INHERI:Derivation of a class from more than one form.
	5.HIERARCHICAL INHERI:Derivation of several classes from one class.
	6.MULTI PATH:DErivation of a class from other derived classes .
	7.MULTI PATH:Derivetion of a class from multiple derived classes.
*/
class a
{
 	char *s1;
	public:
	a()
	{
		cout<<"Constructor in a"<<endl;
		s1=new char[20];
		
	}
	~a()
	{
		cout<<"destructor in a"<<endl;
		delete[] s1;
	}
};
class b:public a
{
	char *s2;
	public:
	b()
	{
		cout<<"Constructor on b"<<endl;
		s2=new char[29];
	}
	~b()
	{
		cout<<"Destructor in b"<<endl;
		delete[]s2;
	}
};
class c:public b
{
	char *s3;
	public:
		c()
		{
			cout<<"Constructor in c"<<endl;
			s3=new char[20];
		}
		~c()
		{
			cout<<"Destructor in c"<<endl;
			delete[] s3;
		}
};
class smart
{
	c *ptr;
	public:
		smart()
		{
			cout<<"smart constructor"<<endl;
			ptr=new c;
		}
		~smart()
		{
			cout<<"Smart destructor"<<endl;
			delete ptr;
		}
		c* operator ->()
		{
			return ptr;
		}
		c operator *()
		{
			return *ptr;
		}
};
int main()
{
/*	c *ptr;
	ptr=new c;
	delete ptr;*/
	smart ptr;
}
