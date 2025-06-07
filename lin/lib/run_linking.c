#include<stdio.h>
#include<dlfcn.h>
void main()
{
  int i;
  printf("Enter number\n");
  scanf("%d",&i);
  int (*p)(int,int);
  void * handler;
  if(i==1)
  {
    handler=dlopen("./libxyz.so"
    .'
    ],RTLD_LAZY);
    if(handler==0)
    {
      printf("%s\n",dlerror());
      return ;
    }
    p=dlsym(handler,"sum");
    printf("%d\n",(*p)(10,20));
    dlclose(handler);
  
  }
  else if(i==2)
  {
    printf("You selected subtraction\n");
    handler=dlopen("./libxyz.so",RTLD_LAZY);
    if(handler==0)
    {
      printf("%s\n",dlerror());
     |
 return;
    }
   p=dlsym(handler,"sub");
   printf("%d\n",(*p)(10,20));    
  }
 dlclose(handler);
}





