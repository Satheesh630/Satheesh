#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream in("file");;
    ofstream out("data");
    string s;
    char ch;
    //short int l,r;
in>>s;
char *l=&s[0];
char *r=&s[s.length()-1];
while(l<r)
        {
            ch=*r;
            *r=*l;
            *l=ch;
            l++;r--;
        }
            cout<<s<<endl;
            out<<s<<endl;
    in.close();
    out.close();
    

}
