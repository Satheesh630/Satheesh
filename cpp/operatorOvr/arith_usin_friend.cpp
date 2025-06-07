#include<iostream>
using namespace std;
class A
{
	public:
	int a,b;
	A(int a=0,int b=0):a(a),b(b){}
	friend A operator+(A,A);
	friend A operator*(A,A);
	friend A operator/(A,A);
	friend A operator -(A,A);
	void display()
	{
		cout<<a<<" "<<b<<endl;
	}	
};
//	------------------------------------STATIC--
/*A operator +(A fir,A sec)
{
	A tmp;
	tmp.a=fir.a+sec.a;
	tmp.b=fir.b+sec.b;
	return tmp;
}*/

//---------------------------- Using DMA
A operator+(A fir,A sec)
{
	A *ptr=new A;
	ptr->a=fir.a+sec.a;
	ptr->b=fir.b+sec.b;
	return *ptr;
}
//*/-------------------------
A operator-(A fir,A sec)
{
	A *ptr=new A;
	ptr->a=fir.a-sec.a;
	ptr->b=fir.b-sec.b;
	return *ptr;
}
A operator*(A fir,A sec)
{
	A *ptr=new A;
	ptr->a=fir.a*sec.a;
	ptr->b=fir.b*sec.b;
	return *ptr;
}
A operator/(A fir,A sec)
{
	A *ptr=new A;
	ptr->a=fir.a/sec.a;
	ptr->b=fir.b/sec.b;
	return *ptr;
}

int main()
{
		A obj1(10,20),obj2(30,40),obj3;
		obj3=obj1+obj2;  //operator +(obj1,obj2);
		obj2=obj3*obj1;
		obj2=obj3/obj1;
		
		obj3.display();
		
		
}
