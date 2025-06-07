#include <stdio.h>
#include<dlfcn.h>
int main()
{
	void *p=dlopen("./header.h",RTLD_LAZY);
	if(p==0)
	{
		printf("%s",dlerror());
		return;
	}
	void (*q)(int);
	q=dlsym(p,"print");
	if(q==0)
	{
		printf("%s",dlerror());
		return;
	}
	(*q)(10);
	
	
}
