#include<stdio.h>
struct st
{
	char ch;
	long long int k;
	int h;
};
int main()
{
	printf("%u\n",sizeof(struct st));
}
