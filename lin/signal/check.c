#include"header.h"
void isr(int n)
{
 printf("PID=%d  n=%d\n",getpid(),n);
}
void main()
{
  signal(2,isr);
  int n=pause();
  printf("n=%d\n",n);
}
