#include<stdio.h>
void main(int argc,char **argv)
{
if(argc!=3)
{
printf("Enter  three arguments src dest\n");
return;
}
FILE *sp,*dp;
sp=fopen(argv[1],"r");
if(sp==0)
{
printf("Src file is not present\n");
return;
}
char ch;
dp=fopen(argv[2],"w");
while((ch=fgetc(sp)!=EOF))
{
fputc(ch,dp);


}


}
