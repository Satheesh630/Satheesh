#include<stdio.h>
#include<stdlib.h>
void main()
{
    char *ptr[4];
    char c1[10],c2[10],c3[10],c4[10];
    ptr[0]=c1;ptr[1]=c2;ptr[2]=c3;ptr[3]=c4;
    scanf("%s\n",c1);
    scanf("%s\n",c2);
    scanf("%s\n",c3);
    scanf("%s\n",c4);
    for(int i=0;i<4;i++)
    {     
        system(ptr[i]);
    }
}
