#pragma pack(8)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct st
{
  char ch;
  int n;
    
}o;

o* fun(void)
{
  o *p=malloc(sizeof(o));
  return p;
}

void main()
{
  o p;
  printf("%ld\n",sizeof(p));
  
}


