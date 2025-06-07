#include"header.h"
typedef struct st 
{
    int l,sl;
}no;
no l_sl_fun(int *ptr,int n)
{
int i,flag=1;
no v;
v.l=ptr[0];
for(i=1;i<n;i++)
{
    if(ptr[i]>v.l)
    {
        v.sl=v.l;
        v.l=ptr[i];
    }
    else if (ptr[i]<v.l && flag)
    {
        flag ^=flag;
        v.sl=ptr[i];
    }
    else if(ptr[i]>v.sl && ptr[i]<v.l)
    {
        v.sl=ptr[i];
    }
}
return v;
}


void main()
{
    int num;
    printf("No of elements\n");
    scanf("%d",&num);
    int a[num];
    for(int i=0;i<num;i++)
    {
    scanf("%d",&a[i]);
    }
   no v=l_sl_fun(a,num);
   printf("l=%d sl=%d\n",v.l,v.sl);
}
