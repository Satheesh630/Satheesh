#include<stdio.h>
#include<string.h>
struct st
{
    int roll;
    float marks;
};

void main()
{
struct st v={10,20.30};
    FILE *p=fopen("data","a+");
    char s[100];
    printf("Enter a string\n");
    scanf("%s",s);
    char ch,ch1;

    ch=fgetc(p);
    ch1=fgetc(p);
    printf("%ld\n",ftell(p));
    fputc(' k',p);
    printf("%ld\n",ftell(p));

    fprintf(p,"%d %f",v.roll,v.marks);
    rewind(p);
    fscanf(p,"%[^\n]",s);
    printf("%s",s);     
    
}
