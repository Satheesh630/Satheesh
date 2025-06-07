#include<iostream>
#include<unistd.h>

using namespace std;
class bankAcc
{

	int accnum;
	double balance;
	string holdername;
	public:
	bankAcc(int accNum,string holdername,double initialamount)
	{
		accnum=accNum;
		holdername=holdername;
		balance=initialamount;
	}
	void show_balance()
	{
		
			cout<<"Your account balance is :"<<balance<<endl;
		
	}
	void deposit(double amount)
	{
		if(amount<=0)
		{
			cout<<"Enter valid amount"<<endl;
			sleep(1);
			return;
		}else
		balance+=amount;
	}
	void withdraw(double amount)//2000
	{
	
	
		if(amount<0)
		{
			cout<<"Invalid amoun"<<endl;
			sleep(1);
			return;
		}
		if(amount >balance)
		{
			cout<<"Insufficient funds"<<endl;
			sleep(1);
			return;
		}
		//cout<<"Your balance :"<<balance<<endl;
		if(amount < balance)
		balance-=amount;
	}
	
};
int main()
{
	bankAcc *user1=new bankAcc(123,"Vinayaka",500);
//	bankAcc user1(123,"Vinayaka",500);
	int op;
	int *ptr;
while(1)
{
system("clear");
cout<<"Enter an option"<<endl<<"1.show account details"<<endl<<"2.deposit"<<endl<<"3.withdraw"<<endl;
cin>>op;
switch (op)
{
	case 1:
			system("clear");
			user1->show_balance();
			sleep(3);
	break;
	case 2:
	ptr=new int;
	cout<<"Enter the amount"<<endl;
	cin>>*ptr;
	user1->deposit(*ptr);
	sleep(1);
	delete ptr;
	break;
	case 3:
	cout<<"Enter the amount to Withdraw"<<endl;
	double d;
	cin>>d;
	user1->withdraw(d);
	break;
	default:
	cout<<"Enter valid option"<<endl;
	
}
}
}
