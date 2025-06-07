#include<stdio.h>
#include<stdarg.h>
void print(int n,...)
{
va_list v;

va_start(v,n);
int num;

	num=va_arg(v,int);
	printf("%d\n",num);
	va_list v1;
   va_copy(v1,v);


num=va_arg(v1,int);
printf("Out side of the loop num=%d\n",num);
va_end(v);
va_end(v1);
}
void My_printf(const char *format,...)
{
va_list v;
va_start(v,format);
vprintf(format,v);
va_end(v);

}
void main()
{
	My_printf("Ganapathi is %d\n",1);
}
