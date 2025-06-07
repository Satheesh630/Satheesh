#include"header.h"
int main()
{
	int *p=calloc(3,4);
	p[0]=1;
	p[1]=5;
	p[2]=6;
	printf("%d %d %d \n",p[0],p[1],p[2]);
	
}
