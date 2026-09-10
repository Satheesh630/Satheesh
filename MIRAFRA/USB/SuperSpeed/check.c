#include<stdio.h>
#include<stddef.h>
struct dev
{
    int n;
    char ch;
     float f;
};

int main()
{
    struct dev obj={10,'A',3.14};
    struct dev*ptr=&obj.f;
    ptr=(struct dev *)((char *)ptr-offsetof(struct dev,f));
    printf("n=%d\n",ptr->n);
}