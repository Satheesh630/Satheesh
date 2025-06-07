#include"header.h"
struct sockaddr_in c_addr;
void main(int argc,char **argv)
{
	struct sockaddr_in s_addr;
	int sfd,len,b;
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sfd<0)
	{
		perror("socket");
		return;
	}
	s_addr.sin_family=AF_INET;
	s_addr.sin_port=htons(atoi(argv[1]));
	s_addr.sin_addr.s_addr=inet_addr(argv[2]);
	len=sizeof(s_addr);
	
	char s[20];
	printf("Enter data\n");
	scanf("%s",s);
	sendto(sfd,s,strlen(s)+1,0,(struct sockaddr*)&s_addr,len);
	close(sfd);
}
