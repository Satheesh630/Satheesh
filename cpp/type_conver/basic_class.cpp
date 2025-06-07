#include<iostream>
using namespace std;
class Time
{
	int hr,min;
	public:
	Time():hr(0),min(0){}
	Time(int n)
	{
		hr=n/60;
		min=n%60;
	}
	void get_data()
	{
		cout<<hr<<":"<<min<<endl;
	}
};
int main()
{
	Time t;
	int n;
	cout<<"Enter umber of minuits"<<endl;
	cin>>n;
	t=n;
	t.get_data();
	
}


