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
/*
	VIRTUAL:-Virtual is used to avoid dulpication of data.
	->If we made a base class as virtual the inheritance is taken care by the compiler 
	that only one copy of the base class is inherited.
	->Without virtual two constructors of a() are copied into d,and two x are copied
	  so ambiuity occurs when we try to access the x in class d;
	  And also two constructors of a are copied and executed.
	  
*/

#if 1
class a
{
	public:
	int x;
	a()
	{
		cout<<"Constructor in a"<<endl;
		cin>>x;
		
	}
	~a()
	{
		cout<<"destructor in a"<<endl;
	}
};
class b:virtual public a
{
	public:
	int y;
	b()
	{
		cout<<"Constructor in b "<<endl;
		cin>>y;
	}	
	~b()
	{
		cout<<"Destructor in b"<<endl;
	}
};
class c:virtual public a
{
	public:
		int z;
		c()
		{
			cout<<"Constructor in c"<<endl;
			cin>>z;
		}
		~c()
		{
			cout<<"Destructor in c"<<endl;
		}
};
class d:public b,public c
{
	public:
	int k;
	d():c(),b()
	{
		cout<<"Constructor in d"<<endl;
		cin>>k;
	}
	~d()
	{
		cout<<"destructor in d"<<endl;
	}
	void get_data()
	{
		cout<<"x= "<<x<<endl;
		cout<<y<<endl;
		cout<<z<<endl;
		cout<<k<<endl;
	}
};
int main()
{
	d obj;
	obj.get_data();
	
}
#endif

#if 0

		//	Without virtual base class
class a
{
	public:
	int x;
	a()
	{
		cout<<"Constructor in a"<<endl;
		cin>>x;
		
	}
	~a()
	{
		cout<<"destructor in a"<<endl;
	}
};
class b:public a
{
	public:
	int y;
	b()
	{
		cout<<"Constructor in b "<<endl;
		cin>>y;
	}	
	~b()
	{
		cout<<"Destructor in b"<<endl;
	}
};
class c:public a
{
	public:
		int z;
		c()
		{
			cout<<"Constructor in c"<<endl;
			cin>>z;
		}
		~c()
		{
			cout<<"Destructor in c"<<endl;
		}
};
class d:public c,public b
{
	public:
	int k;
	d():c(),b()//,a() we cannot call the a directly as a is not directly inherited to d.
	{
		cout<<"Constructor in d"<<endl;
		cin>>k;
	}
	~d()
	{
		cout<<"destructor in d"<<endl;
	}
	void get_data()
	{
	//	cout<<x<<endl;	Here two x are inherited so  ambiguity error occurs.
		cout<<y<<endl;
		cout<<z<<endl;
		cout<<k<<endl;
	}
};
int main()
{
	d obj;
	obj.get_data();
	cout<<"size of a= "<<sizeof(a)<<endl;
	cout<<"size of b= "<<sizeof(b)<<endl;
	cout<<"size of c= "<<sizeof(c)<<endl;
	cout<<"size of d= "<<sizeof(d)<<endl;
	//Total size of d= 20 i.e 8+8+4=20.
}
#endif
