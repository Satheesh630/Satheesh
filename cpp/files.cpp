#include<iostream>
#include<fstream>
using namespace std;
class a
{
 public :
 void fun()
 {
   cout<<"Hello world"<<endl;
 }
};
int main()
{
  ifstream in("data");
  ofstream out;
  out.open("data1");
  string s;
  char ch ;
while((ch=in.get()!=EOF))  
  {
   out<<ch;
  } 
 in.close();
 out.close();

}
