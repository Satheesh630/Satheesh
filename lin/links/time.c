#include<stdio.h>
#include<time.h>
void main()
{
    time_t t;
    t=time(0);
    printf("%s\n",ctime(&t));

}
