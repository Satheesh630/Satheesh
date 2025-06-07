#include<iostream>
using namespace std;
class st
{
	int roll;
	string name;
	public:
	st()
	{
	cout<<"Enter roll and name "<<endl;
	cin>>roll>>name;
	}
	friend ostream&   operator<<(ostream& ref,st var)
	{
		ref<<var.roll<<" "<<var.name<<endl;
		return ref;
		
	/* cout<<obj<<obj1;
	cout<<obj=operator(cout,obj)--if this returns nothing obj1 will not be resolved 
	after execution of first part 
	it looks like 
	<<obj1;
	If we return reference of ostream 
	cout<<obj1;
	*/
	}
};
int main()
{
	st obj,obj1;
	//cout<<obj;//cout.operator<<(&cout,obj) internal call if ovrld using member fun
	cout<<obj<<obj1;//operator<<(cout,obj); in friend fun overload
	
}
