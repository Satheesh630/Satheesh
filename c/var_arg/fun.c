#include<stdio.h>
#include<stdarg.h>
int sum(int n,int m,...)
{
  va_list v;
  va_start(v,m);
  int sum=0,num=0;
  for(int i=0;i<m;i++)
  {
    num=va_arg(v,int);
    sum=sum+num+n;
  }
  va_list a;
  va_copy(a,v);
  va_start(m,v);
  {
  int num=0,sum=0;
  for(int i=0;i<m;i++)
  {
   num=va_arg(v,int);
   sum=sum+num;
  }
  printf("num in copy is =%d \n",sum+n);
  }
  va_end(a);
  va_end(v);	
  return sum;

}

void main()
{
 int bu=sum(10,2,1,2);
 printf("%d\n",bu);
}
