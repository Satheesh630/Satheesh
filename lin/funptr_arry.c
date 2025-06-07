#include"header.h"
int sum(int a ,int b)
{
return a+b;
}
int sub(int a ,int b)
{
 return a-b;
}
int mul(int a,int b)
{
 return a*b;
}
int dive(int a, int b)
{
return a/b;
}
typedef int(*P)(int,int);
void main()
{
  int a=10,b=20;
  P p[4]={sum,sub,mul,dive};
  for(int i=0;i<4;i++)
  printf("%d\n",(*p[i])(a,b));
}
