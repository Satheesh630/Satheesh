#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    if(fork())
    {
        system("clear");
        if(fork())
        {
        system("ls");
        if(fork())
        {
         system("cal");
        }
        }
    }
}
