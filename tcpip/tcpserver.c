#include"header.h"
struct sockaddr_in c_addr;
void main(int argc,char **argv)
{
	struct sockaddr_in s_addr;
	int sfd,len,b;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{
		perror("socket");
		return;
	}
	s_addr.sin_family=AF_INET;
	s_addr.sin_port=htons(atoi(argv[1]));
	s_addr.sin_addr.s_addr=inet_addr(argv[2]);
	len=sizeof(s_addr);
	b=bind(sfd,(struct sockaddr *)&s_addr,len);
	if(b<0)
	{
		perror("bind");
		return;
	}
	if(listen(sfd,5)<0)
	{
		perror("listen");
		return;
	}
	int nsfd=accept(sfd,(struct sockaddr*)&c_addr,&len);
	if(nsfd<0)
	{
		perror("nsfd");
		return;
	}
	char s[20];
	read(nsfd,s,sizeof(s));
	printf("In server read data=%s\n",s);
		
}
