#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str="hello";
	
	char &ch=str.back();
	char *ptr=&ch;
}
