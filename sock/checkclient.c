#include"header.h"
int main()
{
int sfd,len;
struct sockaddr_in server_id;
sfd=socket(AF_INET,SOCK_STREAM,0);
if(sfd<0)
{
 perror("Socket");
 return 0;
}
perror("Socket");

server_id.sin_family=AF_INET;
server_id.sin_port=htons(3000);
server_id.sin_addr.s_addr=inet_addr("127.0.0.1");
len=sizeof(server_id);
if(connect(sfd,(struct sockaddr*)&server_id,len)<0)
{
perror("connect");
return 0;
}
perror("connect");
char s[20];
while(1){
printf("enter string from user\n");
scanf("%s",s);
write(sfd,s,strlen(s)+1); //writing data to server
}
close(sfd);

}

