#include"header.h"
int main()
{
	int a[2];
	pipe(a);
	printf("%d %d \n",a[0],a[1]);
	
	char buf[10];
	read(a[0],&buf,10);
	printf("Data=%s\n",buf);	

}	
