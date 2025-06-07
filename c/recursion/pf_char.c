#include<stdio.h>
void print(char *);
void main()
{
char ch[20];
printf("Enter the string \n");
scanf("%s",ch);
print(ch);
}
void print(char *p)
{
if(*p)
{
printf("%c",*p);
print(p+1);
}
else return;



}
