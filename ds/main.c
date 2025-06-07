#include"header.h"
int main()
{
	int op;
	system("clear");
	while(1)
	{
	printf(BOLDBLACK"Enter an option\n");
	printf(BOLDBLACK"0)EXIT\n1)Add at begin\n2)Print nodes\n3)Add_End\n4)Save File\n5)Read File\n6)search_node\n7)Delete a node\n8)Reverse nodes\n"RESET);
	scanf("%d",&op);
	system("clear");
	switch (op)
	{
		case 1:
			add_begin(&headptr);
		break;
		case 2:
		add_print(headptr);
		break;
		case 3:
			add_end(&headptr);
			break;
		case 4:
			save_file(headptr);
			break;
		case 5:
			read_file(&headptr);
			break;
		 case 0:
			return 0;
		case 6:
			 search_node(headptr);
			 break;
		case 7:
			del_node(&headptr);
			break;
		case 8:
			 rev_nodes(&headptr);
			 break;
			 
		default:
		printf(RED"Entered wrong option\n");
	}
	}
}
void rev_nodes(SLL **ptr)
{
	if(*ptr==0)
	{
		printf(RED"No Records found\n");
		return;
	}
	int c=node_count(*ptr);
	SLL **arr=calloc(c,sizeof(SLL*)),*sim=*ptr;
	int i=0;
	while(sim)
	{
		arr[i++]=sim;
		sim=sim->next;
	}
	*ptr=arr[--i];
	sim=*ptr;
	while(i>=1)
	{
		sim->next=arr[--i];
		sim=sim->next;
	}
	sim->next=0;
	
}	
int node_count(SLL *ptr)
{
	int c=0;
	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}
void del_node(SLL **ptr)
{
	if(*ptr==0)
	{
		printf(RED"No Records to delete\n"RESET);
		return;
	}
	int roll;
	printf("Enter Roll number to delete\n");
	scanf("%d",&roll);
	SLL *del=*ptr,*prev;
	while(del)
	{
		if(del->roll==roll)
		{
			if(del==*ptr)
			{
				*ptr=del->next;
				free(del);
			}
			else
			{
				prev->next=del->next;
				free(del);
				del=prev->next;
			}
		}
		else
		{
			prev=del;
			del=del->next;
		}
	}
}
void search_node(SLL *ptr)
{
	int roll;
	printf("Enter roll\n");
	scanf("%d",&roll);
	if(ptr==0)
		{printf("No data Available\n");
		return;}
		int c=0;
	while(ptr)
	{
		if(ptr->roll==roll)
		{
			printf(BOLDRED"%d %s\n",ptr->roll,ptr->name);
			c++;
		}
	
		ptr=ptr->next;		
	}
	if(c==0)
		printf("No records available\n");
}

void read_file(SLL **ptr)
{
	FILE *fd=fopen("data.txt","r");
	if(fd==0)
	{	
		printf(RED"File can't be opened\n");
		return;
	}
	SLL *buf=calloc(1,sizeof(SLL));
	while(fscanf(fd,"%d %s",&buf->roll,buf->name) !=EOF)
	{
		SLL *new=calloc(1,sizeof(SLL));
		new->roll=buf->roll;
		strcpy(new->name,buf->name);
		if(*ptr==0)
		{
			*ptr=new;
		}
		else
		{
			new->next=*ptr;
			*ptr=new;
		}
	}
}
void save_file(SLL *ptr)
{
	if(ptr==0)
	{
		system("clear");
		printf(RED"No records are present\n");
		return;
	}
	FILE *fd=fopen("data.txt","w");
	if(fd==0)
	{
		printf(RED"Can't Open File\n");
		return;
	}
	while(ptr)
	{
	fprintf(fd,"%d %s\n",ptr->roll,ptr->name);
	ptr=ptr->next;
	}
	fclose(fd);
}
void add_end(SLL **ptr)
{	
	SLL *new,* last;
	new=calloc(1,sizeof(SLL));
	printf("Enter roll and name\n");
	scanf("%d %s",&new->roll,new->name);
	if(*ptr==0)
	{
		*ptr=new;
	}
	else
	{
		last=*ptr;
		while(last->next)
		{
			last=last->next;
		}
		last->next=new;
	}
}
void add_begin(SLL **ptr)
{
	SLL *new=malloc(sizeof(SLL));
	printf("Enter roll and name\n");
	scanf("%d %s",&new->roll,new->name);
	system("clear");
	new->next=*ptr;
	*ptr=new;
}
void add_print(SLL *ptr)
{
	if(ptr==0)
	{
		printf("No records are present\n");
		return ;
	}	
	while(ptr)
	{
		printf("%-4d %-10s\n",ptr->roll,ptr->name);
		ptr=ptr->next;
	}
}
void * clear(void *ptr)
{
	system("clear");
	wait(0);
}














