#include<stdio.h>
struct uart
{
	unsigned int baud:3;
	unsigned int parity:2;
};
int main()
{
	struct uart obj;
	obj.baud=15;
	obj.parity=2;
	printf("baud %d parity%d\n",obj.baud,obj.parity);
}
