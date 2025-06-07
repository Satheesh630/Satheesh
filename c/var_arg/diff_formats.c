#include<stdio.h>
#include<stdarg.h>
int print(char*fmt,...)
{ 
   va_list v;
   va_start(v,fmt);
   char ch,*s;
   int d;
   while(*fmt)
   {
   		switch(*fmt++)
   		{
   			case 'd'://variable pointer automatically movs to the neext argument internally but to know the arg type we are using string as type indicator accordingly we are providing type and storing.Even if we dont increment the fmt pointer internally va_arg moves to next argument,if we unable to catch that whith correct type itll display garbage value.Try not to increment the fmt char pointer.
	   			d=va_arg(v,int);
	   			printf("Decimal %d\n",d);
	   			break;
   			case 's':
   				s=(char *)va_arg(v,char *);
   				printf("%s\n",s);
   				break;
   			case 'c':
   				ch=(char)va_arg(v,int);
   				printf("%c\n",ch);
   				break;
   		}
   		va_end(v);
   }
}
void main()
{
print("dcssd",5,'c',"Vinayaka","sunday",23432);//According to the given characters in the string in first argument the values are printed



}













