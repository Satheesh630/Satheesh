#include"header.h"
void main()
{
    int sfd,len;
    struct sockaddr_in client;
    sfd=socket(AF_INET,SOCK_STREAM,0);
    client.sin_family=AF_INET;
    client.sin_port=htons(3000);
    client.sin_addr.s_addr=inet_addr("127.0.0.1");
    len=sizeof(client);
    if(connect(sfd,(struct sockaddr*)&client,len)<0)
    {
        perror("Connect");
        return;
    }
    printf("Connected successfully.......\n");
    char s[29];
    while(1)
    {
    printf("Enter any string\n");
    scanf("%s",s);
    write(sfd,s,strlen(s)+1);
    }
    

    close(sfd);
  
}
