#include"header.h"
void isr(int n)
{ 
  static int b,m;
  printf("PID =%d n=%d\n",getpid(),n);
  if(n==2)
  {
    b++;
    if(b==3)
    {
      signal(2,SIG_DFL);
      printf("%d times reamaining\n",(4-b));
    }
    else
    printf("%d times reamaining\n",(4-b));
  }
  else if(n==3)
  {
    m++;
    if(m==3)
    {
      signal(3,SIG_DFL);
      printf("%d times ctrl+\\ remaining\n",(4-m));
    }
    else 
    printf("%d times ctrl+\\ remaining\n",(4-m));
  }
  
}
void main()
{
  signal(2,isr);
  signal(3,isr);
 while(1); 
}
