#include"header.h"
typedef int(*p)(int,int);
int mul(int a,int b)
{
  return a+b;
}
p fun(int(*p)(int,int))
  {
    return mul;
  }
  
int sum(int a,int b)
{
  return a+b;
}

void main()
{

int(*p)(int,int);
 p=fun(sum);
 printf("%d\n",(*p)(10,20));
}
 

