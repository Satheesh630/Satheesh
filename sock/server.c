#include"header.h"

void main()
{
struct sockaddr_in server,client ;
    int sfd,nsfd,len;
    sfd=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(3000);
    server.sin_addr.s_addr=inet_addr("0.0.0.0");
    len=sizeof(server);
    if(bind(sfd,(struct sockaddr*)&server,len)<0)
    {
        perror("bind");
        return;
    }
    if(listen(sfd,5)<0)
    {
        perror("listen");
        return;
    }
    printf("Waitng to connect with the client.......\n");
    
    nsfd=accept(sfd,(struct sockaddr*)&client,&len);
    if(nsfd<0)
    {
        perror("Accept");
        return;
    }
    printf("Your Bluetooth device connected successfully\n");
    char s[30];
    while(1)
    {
        read(nsfd,s,sizeof(s));
        printf("%s\n",s);
    }    


  close(sfd);
  close(nsfd);  
}
