#include<stdio.h>
struct st
{
  unsigned int n:3;

};
void main()
{
  struct st o;
  o.n=8	;
  printf("%d \n",o.n);
}
