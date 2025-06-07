#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void isr(int n)
{
  printf("SIG NO =%d\n",n);
  for(int i=0;i<3;i++)
  printf("Num=%d\n",i);
  alarm(1);
  
}
void main()
{
  signal(SIGALRM,isr);
  alarm(3);
  signal(2,isr);
  while(1);
}
