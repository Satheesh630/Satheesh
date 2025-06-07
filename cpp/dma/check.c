#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double d=2.0;
	cout<<fixed<<setprecision(3)<<d<<endl;
	--d;
	cout.unsetf(fixed);
	cout<<d<<endl;
}
