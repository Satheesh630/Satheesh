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
 	virtual void fun()
 	{
 		cout<<"In virtual"<<endl;
 	}
 	friend int main();
	public:
	a()
	{
		cout<<"Constructor in a"<<endl;
		s1=new char[20];
		
	}
	virtual ~a()
	{
		cout<<"destructor in a"<<endl;
		delete[] s1;
	}
};

int main()
{
	a obj;	
	(*(&obj)).fun();
}
