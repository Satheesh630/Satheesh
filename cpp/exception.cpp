#include<iostream>
using namespace std;
void emergency() 
{
  cout<<"In Emergency "<<endl;
}
int main()
{
  set_terminate(emergency);
  try
  {
    throw 100;
    throw "sathee";
  }
  catch(const char *ptr)
  {
    cout<<ptr<<endl;
  }
 
  
    
}
