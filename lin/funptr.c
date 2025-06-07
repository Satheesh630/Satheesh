#include<stdio.h>
#include<unistd.h>
void fun1(int *p,int *q)
{
    int t;
    t=*p;
    *p=*q;
    *q=t;
}
int fun(int *ptr,int n)
{
    int l=ptr[0];
    for(int i=0;i<n;i++)
    {
        if(ptr[i]>l)
            l=ptr[i];
    }
    return l;
}
int secondL(int *p,int n)
{
    int l,sl;
    if(p[0]>p[1])
    {
        l=p[0];
        sl=p[1];    
    }

    if(n<2){
    printf("Array should contain more than one element\n");
     return -1;
    }
for(int i=0;i<n;i++)
{
    if(p[i]>l)
    {
        l=p[i];
    }
    else if(p[i]>sl && p[i] !=l)
    sl=p[i];
    }
return sl;
}
void main()
{ 
    int a[]={1,2,3,345,876};
    int (*p)(int *,int)=fun;
    int i=secondL(a,5);
    printf("largesst is =%d\n",i);
}
