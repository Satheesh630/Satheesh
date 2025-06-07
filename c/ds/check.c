#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
int rollnum;
char name[20];
float marks;
struct st *next;
}v;
void main()
{

v *p,*headptr=0,*new;
int i=0;
while(i<3)
{
new =malloc(sizeof(v));
printf("Enter marks  name marks\n");
scanf("%d%s%f",&new->rollnum,new->name,&new->marks);
new->next=headptr;
headptr=new;
i++;
}
new=headptr;
for( ;new->next;)
{
printf("%d %s %f\n",new->rollnum,new->name,new->marks);
new=new->next;

}

}
