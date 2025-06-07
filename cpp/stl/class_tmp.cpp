#include<iostream>
using namespace std;
template <class type>
class a
{
	type a;
	public:
		void set_data()
		{
			cout<<"Enter Data"<<endl;
			cin>>a;
		}
		void get_data()
		{
			cout<<a<<endl;
			cout<<typeid(a).name()<<endl;
		}
};
int main()
{
	a <int>obj;
	obj.set_data();
	obj.get_data();
}
