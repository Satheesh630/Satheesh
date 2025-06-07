#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream ot("file",ios::in|ios::out|ios::app);
    int num;
    string s,S="satheesh kumar";
    float m;
    cout<<"Enter num string and m"<<endl;
    cin>>num>>s>>m;
    ot<<num<<" "<<s<<" "<<m<<" "<<S<<endl;
    
    
    ot.close();
}
