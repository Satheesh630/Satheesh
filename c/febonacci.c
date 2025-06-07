#include<stdio.h>
void main()
{
int f=0,s=1,t=0;
printf("%d",f);
printf("%d",s);
for(int i=2;i<100;i++)
{
t=f+s;
printf("%d ",t);
//int p;
f=s;
s=t;
}

}
