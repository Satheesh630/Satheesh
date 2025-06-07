#include<stdio.h>
#include"header"
struct st v;


int x=1000;

int main()
{
v.x=100;v.y=200;
	printf("actual x=%d\n",x);
	printf("Actual str=%d %d\n",v.x,v.y);
	printf("Accessed in another file\n");
	px();ps();
	
	printf("After modification\n");
		printf("actual x=%d\n",x);
	printf("Actual str=%d %d\n",v.x,v.y);
	
}

void px()
{
	printf("in func check=%d\n",x);
	x=x+100;
}
void ps()
{
	printf("structure variable is %d %d\n",v.x,v.y);
	v.x=20000,v.y=30000;
	
}
 
