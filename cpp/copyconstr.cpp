#include<iostream>
#include<cstring>
using namespace std;
extern int sum(int,int);
class a
{
  public:
  
 
     const int x=100,y=200;char *p;
     static int st;
     string s="Satheesh";
     a(){}
     a(int p,int q):x(p),y(q)
     {
       cout<<"Parameterised construct"<<endl;
     }
     a(a& b):x(b.x),y(b.y)
     {
       cout<<"Reference"<<endl;
     }
   

    void get_data()
    {
      cout<<x<<" "<<y<<endl;
    }
     void get_data(int a)
    {
      cout<<x+a<<" "<<y<<endl;
    }

};

int a::st;
int main()
{
   int k=sum(1,2);
   cout<<k<<endl;    
}



