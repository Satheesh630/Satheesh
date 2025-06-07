#include<iostream>
using namespace std;
class B
{
	float a,b;
	public:
	B(){}
	B(float a,float b):a(a),b(b){}
	B operator -(B var)
	{
		B tmp;
		tmp.a=a-var.a;
		tmp.b=b-var.b;
		return tmp;
	} 
	B operator +(B var)
	{
		B tmp;
		tmp.a=a+var.a;
		tmp.b=b+var.b;
		return tmp;
	}
	B operator *(B var)
	{
		B temp;
		temp.a=a*var.a;
		temp.b=b*var.b;
		return temp;
	}
	B operator / (B sec)  //B operator /(const B *this,B sec);
	{
	
			B temp;
		if(sec.a==0 || sec.b==0)
		throw "dividing with zero";
		
		
		temp.a=a/sec.a;            //temp.a=this->a/sec.a internally
		temp.b=b/sec.b;
		
		return temp;
	
	}
	void display()
	{
		cout<<fixed<<a<<" "<<b<<endl;
	}
	
};
int main()
{
	B a(10,20),b(10,0),c;
//	c=a-b;           // c=a.operator -(&b,b);
//	c=a+b;	
	try{
	c=a/b;     //c=a.operator
	}
	catch(const char *s)
	{
	cout<<s<<endl;
	}
	c.display();
}
