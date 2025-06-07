#include"header.h"
int main()
{
	
	char buf[10];
	printf("Enter a string\n");
	scanf("%s",buf);
	
	write(4,&buf,strlen(buf));

}	
