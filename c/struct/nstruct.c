#include<stdio.h>
#include<stdlib.h>
struct st
{
	int i;
	char name[20];
	struct one
	{
		char village[20];
		int pincode;
	}v;

};

void main()
{
struct st *p;
p=malloc(sizeof(p));
p->v.pincode=517247;
printf("Pin code =%d \n",p->v.pincode);
}
