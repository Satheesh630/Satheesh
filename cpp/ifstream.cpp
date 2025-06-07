#include<iostream>
#include<fstream>
using namespace std;
int main(int argc ,char **argv)
{
if(argc <3)
{
  cout<<"Usage :..."<<endl;
  return 0;
}
  ifstream in;
  in.open(argv[1]);
  if(in.fail())
  {
    cout<<"No file found"<<endl;
    return 0;
  }
  string s;
  ofstream out;
  out.open(argv[2]);
  while(getline(in,s))
  {
    out<<s<<endl;
    
  }

in.close();
out.close();

#if 0
  ifstream in;
  if(argc<2)
  {
    cout<<"Usage..."<<endl;
    return 0;
  }
  in.open(argv[1]);
  if(in.fail())
  {
    cout<<"File is not present"<<endl;
  }
  string  ch;
  while((getline(in,ch))!=0)
  {
    cout<<ch<<endl;
  }
  in.close();


  ofstream put;
  put.open("data");
  int i,j;
  for(i=0;i<5;i++)
  {
   for(j=0;j<5;j++)
   {
     if(j<=i)
     {
       put<<"*";
     }
     else 
     put<<" ";
   }
   put<<endl;
  }
  
  
  #endif



#if 0
  ifstream fin;
  fin.open("data");
  string s;
  //char s[10];
  //fin>>s;
  //fin.getline(s,30);
  getline(fin,s);
  cout<<s<<endl;
  fin.close();
#endif 
}
