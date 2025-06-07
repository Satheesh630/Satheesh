#include"header.h"
void main()
{
	sll *headptr=0;
	int op;
	while(1)
	{
		printf("Enter option..\n1.add_begin()                 \n2.print_node\n3.add_end\n4.save_file()\n");
		scanf("%d",&op);
		switch (op)
		{
			case 1:add_begin(&headptr);break;
			case 2:print_node(headptr);break;
			case 3:add_end(&headptr);break;
			case 4:save_file(headptr);break;
			case 16:exit(0);
		}
	}
}


void save_file(sll *ptr)
{
system("clear");
if(ptr==0)
{
printf("\033[34m***************************\033[0m\n");
printf("\033[20mNo records found\033[0m\n");
printf("\033[34m***************************\033[0m\n");
return;
}
FILE *fp=fopen("data.txt","w");
while(ptr)
{
fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
ptr=ptr->next;
}
fclose(fp);
}
////////////////////////////////
void add_begin(sll **ptr)
{
	sll *new=malloc(sizeof(sll));
	printf("Enter rollno name and marks\n");
	scanf("%d%s%f",&new->rollno,new->name,&new->marks);
	new->next=*ptr;
	*ptr=new;
}
//////////////////////////////////////
void add_end(sll **ptr)
{
	sll *new,*last;
	new=malloc(sizeof(sll));
	printf("Enter rollno name marks\n");
	scanf("%d%s%f",&new->rollno,new->name,&new->marks);
	new->next=0;
	if(*ptr==0)
	{
		*ptr=new;
	}else
	{
		last=*ptr;
		while(last->next)
			last=last->next;
		last->next=new;
	}
}

/////////////////////////////////////////
void print_node(sll *ptr)
{
	printf("\033[34m***************************\033[0m\n");
	if(ptr==0)
	{
		printf("No records found\n");
		printf("\033[34m***************************\033[0m\n");
		return;
	}
	while(ptr)
	{
		printf("%d %s %f \n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;

	}
	printf("\033[34m***************************\033[0m\n");

}
