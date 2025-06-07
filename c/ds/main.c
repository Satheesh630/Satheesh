#include"header.h"
void main()
{
sll *headptr=0;
int op;
while(1)
{
printf("Enter an option\n");
printf("1.add_begin\n2.add_end\n4.print_node\n6.save_file\n7.read_file\n");
scanf("%d",&op);

switch (op)
{
case 1:add_begin(&headptr);break;
case 2:add_end(&headptr);break;
case 3:
case 4:print_node(headptr);break;
case 5:
case 6:save_file(headptr);break;
case 7:read_file(&headptr);break;
case 8:
case 9:
case 10:
case 11:
case 12:
case 13:
case 14:
case 15:
case 16: exit(0);
default :
printf("\033[31m Warning : Entered wrong choice\033[0m \n");
}
}
}




void add_begin(sll **ptr)
{
system("clear");
sll *new;
new=malloc(sizeof(sll));

printf("Enter rollno name marks\n");
scanf("%d%s%f",&new->rollno,new->name,&new->marks);
new->next=*ptr;
*ptr=new;

}
void print_node(sll *ptr)
{
printf("\033[33m******************\n\033[0m");
if(ptr==0)
{
printf("No records found\n");
return;
printf("\033[33m******************\033[0m\n");
}
while(ptr)
{
printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
ptr=ptr->next;
}
printf("\033[33m******************\033[0m\n");
}
/////////////////////////////////////
void save_file(sll *ptr)
{
system("clear");
printf("\033[33m *********************\033[0m\n");
if(ptr==0)
{
printf("No records found\n");
printf("\033[33m *********************\033[0m\n");
return ;
}
FILE *fp;
fp=fopen("data","w");
while(ptr)
{
fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
ptr=ptr->next;
}
fclose(fp);
}
/////////////////////////////////////////////////////

void add_end(sll **ptr)
{
sll *new,*last;
new=malloc(sizeof(sll));
printf("Enter rollno name marks\n");
scanf("%d%s%f",&new->rollno,new->name,&new->marks);
new->next=0;
if(*ptr==0)
*ptr=new;
else 
{
last=*ptr;
while(last->next)
last=last->next;
last->next=new;
}
}
///////////
void read_file(sll **ptr)
{

FILE *fp;
fp=fopen("data","a+");
if(fp==0)
{
printf("file not found\n");
return;
}
sll *new,*last;
while(1)
{
new= malloc(sizeof(sll));
new->next=0;
if(fscanf(fp,"%d%s%f",&new->rollno,new->name,&new->marks)==EOF)
{
break;
}
if(*ptr==0)
{
*ptr=new;
}
else
{
last=*ptr;
while(last->next)
last=last->next;
last->next=new;
}
}
}
















