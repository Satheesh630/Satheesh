#include<stdlib.h>
#include<stdio.h>
int main()
{
	void *ptr=malloc(10001919);
	printf("Memory leak created\n");
	free(ptr);
}
