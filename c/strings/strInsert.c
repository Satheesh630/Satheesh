#include<stdio.h>
#include<string.h>
void main()
{
    char str[]="sathsh",sub[]="ee",buf[20];
    strncpy(buf,str+4,strlen(str)-3);
    printf("%s\n",buf);
    strcpy(str+4,sub );
    strcat(str,buf);
    printf("%s\n",str);
}
