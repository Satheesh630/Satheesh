#include<stdio.h>
#include<dlfcn.h>
int main()
{
    int(*p)(int,int);
    int i=10,j=20;
    void *handler;
    dlopen("./lib.so",RTLD_LAZY);
    if(handler==0)
    {
        printf("%s\n",dlerror());
        return 1;
    }
    printf("Before dlsym \n");
    p=dlsym(handler,"sub");
    
    
       
    if(p==0)
    perror("dlsym");
    //printf("sum=%d\n",n);
    dlclose(handler);
}

