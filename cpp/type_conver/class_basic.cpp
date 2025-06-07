#include<iostream>//There is an inbuilt function in cpp called time so use Time
using namespace std;
class Time
{	
	int hr,min;
	public:
	Time()
	{
		cout<<"Enter in hrs and mins"<<endl;
		cin>>hr>>min;
	}
	operator int ()
	{
		return hr*60+min;
	}
	
};
int main()
{
	Time t;
	int n;
	n=t;
	cout<<n<<endl;

	
}
