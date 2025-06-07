#include"header.h"
void main()
{
struct sockaddr_in server,client;
int sfd,nsfd,len;
sfd=socket(AF_INET,SOCK_STREAM,0);
 if(sfd<0)
 {
 perror("socket worong dear");
 return;
 }
 server.sin_family=AF_INET;
 server.sin_port=(9000);
 server.sin_addr.s_addr=inet_addr("0.0.0.0");
 len=sizeof(server);
  if(bind(sfd,(struct sockaddr*)&server,len)<0)
  {
 perror("bind");
 return;
}
  if(listen(sfd,5)<0);
  {
  perror("listen");
  return;
}
   nsfd=accept(sfd,(struct sockaddr*)&client,&len);
   if(nsfd<0)
{
perror("accept");
return;
}
  
  char s[69];
  printf("sucess and waiting");
  while(1)
  {
  read(nsfd,s,sizeof(s));
  printf("%s",s);
  }
  close(sfd);   
  close(nsfd);
}

