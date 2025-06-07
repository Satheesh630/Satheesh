#include<stdio.h>
#include<stdlib.h>
struct st
{
	int i;
	char ch[20];
	float f;

};

struct st ** alloc (int );
void main()
{
	int n;
	printf("Enter number of students\n");
	scanf("%d",&n);
	struct st **p;
	p=alloc(3);
	for(int i=0;i<n;i++)
	{
	printf("Enter student roll nuber\n");
	scanf("%d",&p[i]->i);

	}
printf("Roll no %d\n",p[0]->i);
}
struct st ** alloc(int n)
{
	struct st **p=malloc(sizeof(struct st *)*n);
	for(int i=0;i<n;i++)
		p[i]=malloc(sizeof(struct st));

	return p;
}

