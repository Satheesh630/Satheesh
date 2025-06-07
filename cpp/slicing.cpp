#include<iostream>
using namespace std;
class pure
{
  public:
    virtual void get_data()=0;
};
class a:private pure
{
   char *p;
   int A=10,b=20;
    
  public :
    a()
    {
      cout<<"Constructor in a"<<endl;
      p=new char[20];
    }
    virtual ~a()
    {
      cout<<"Destructor in a "<<endl;
      delete []p;
    }
    void get_data()
    {
      cout<<"IN GET DATA"<<endl;
    }
     
};
class b:public a 
{
   char *p;
  public :
    b()
    {
      cout<<"Constructor in b"<<endl;
      p=new char[20];
    }
    ~b()
    {
      cout<<"Destructor in b "<<endl;
      delete []p;
    }
    
};
class c:public b
{
   char *p;
  public :
    c()
    {
      cout<<"Constructor in c"<<endl;
      p=new char[20];
    }
    ~c()
    {
      cout<<"Destructor in c "<<endl;
      delete []p;
    }
};
int main()
{
   int a;
   cout<<"ENter number "<<endl;
   cin>>a;
   try
   {
     if(a==1)
       throw "NUMBER IS 1";
   }
   catch (const char *p)
   {
     cout<<dec<<p<<endl;
   }
} 















