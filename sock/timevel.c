#include"header.h"
int main()
{
	int a,ret;
	fd_set v; 
	struct timeval t;
	printf("enter a value\n");
	FD_ZERO(&v);
	FD_SET(0,&v);

	t.tv_sec=5;
	t.tv_usec=0;

	ret=select(1,&v,0,0,&t);
	if(ret<0)
	{ 
		perror("Select");
		return 0;
	}
	else if(ret==0)
	{
		printf("Time out/Time expired\n");
	}
	else
	{
		scanf("%d",&a);
		printf("STDIN:%d\n",a); 
	}
}

