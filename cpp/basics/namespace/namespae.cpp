#include<iostream>
using namespace std;
namespace hr
{
	namespace salary
	{
		void salary()
		{
			cout<<"Salary is 1000000"<<endl;
		}
	
	}
	namespace ceo
	{
		void ceo()
		{
			cout<<"You are the CEO Buddy"<<endl;
		}
	
	}

}
int main()
{
hr::salary::salary();

}
