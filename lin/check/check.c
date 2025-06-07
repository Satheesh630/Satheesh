#include<stdio.h>
#include<dlfcn.h>

int main()
{
	int (*p)(const char *,...)	;
	void *handler;
	handler=dlopen("libc",RTLD_LAZY);
	if(handler==0)
		{
		printf("%s",dlerror());
		}
}
