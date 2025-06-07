#include"header.h"
void main()
{
	int fd[2];
	pipe(fd);
	printf("%d %d \n",fd[0],fd[1]);	
	if(fork())
	{
			char ch[20];
			close(fd[0]);
			perror("closep[0]");
			printf("Enter the data\n");
			scanf("%s",ch);
			write(fd[1],ch,strlen(ch));
			perror("write");
			
	}
	else
	{
		char s[10];
		read(fd[0],s,10);
		perror("read");
		printf("%s\n",s);
		
	}
}
