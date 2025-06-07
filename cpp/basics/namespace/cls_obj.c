#include<iostream>
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
		cout<<"Enter account number"<<endl;
		int temp;
		cin>>temp;
		if(temp==accnum)
		{
			cout<<"Your account balance is :"<<balance<<endl;
		}
		else
		cout<<"Invalid account number!"<<endl;
	}
	void deposit(double amount)
	{
		balance+=amount;
	}
	void withdraw(double amount)
	{
		if(amount<0 || amount <balance)
		{
			if(amount<0)
			cout<<"Enter valid amount"<<endl;
			else if(amount<balance)
			cout<<"Insufficient funds"<<endl;
		}
		balance-=amount;
	}
	
};
int main()
{
	bankAcc user1(123,"Vinayaka",500);
	int op;
	int *ptr;
while(1)
{
cout<<"Enter an option"<<endl<<"1.show account details"<<endl<<"2.deposit"<<endl<<"3.withdraw"<<endl;
cin>>op;
switch (op)
{
	case 1:
			system("clear");
			user1.show_balance();
			wait(4);
	break;
	case 2:
	ptr=new int;
	cout<<"Enter the amount"<<endl;
	cin>>*ptr;
	user1.deposit(*ptr);
	delete ptr;
	break;
	case 3:
	cout<<"Enter the amount to deposite"<<endl;
	cin>>*ptr;
	user1.withdraw(*ptr);
	break;
	
	
}
}
}
