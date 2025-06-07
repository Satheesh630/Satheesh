#include<stdio.h>
#include<stdarg.h>
#define typeof(x) printf("Type of "#x":%s\n",#x)
void print(char fmt,...)
{
  va_list v;
  printf("size=%ld\n",sizeof(v));
  
}
void main()
{
 //print(3,1,23,3);
 int x=10;
 typeof(int);
}
