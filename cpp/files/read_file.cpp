#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream in("file");

    
    int num;
    string s;
    float m;
    in>>s>>num>>m;
    cout<<num<<" "<<s<<" "<<m<<endl;
    in.close();
}
