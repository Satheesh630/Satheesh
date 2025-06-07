#include<iostream>
#include<iomanip>
#include<fstream>
#include<unistd.h>
using namespace std;
typedef struct st
{
	int roll;
	char name[10];
	float f;

}base;

int main() 
{

	base v={10,"satheesh",100},v1;
	fstream fio("data",ios::in|ios::out|ios::trunc);

	fio.write((char *)&v,sizeof(v));
	fio.seekp(0,ios::beg);	
	fio.read((char*)&v1,sizeof(v1));
	cout<<v1.roll<<endl<<v1.name<<endl<<v1.f<<endl;
}

