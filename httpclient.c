#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int sockfd;
	char buffer[1024];
	struct sockaddr_in servaddr;
	
		sockfd=socket(AF_INET,SOCK_STREAM,0);
		if(sockfd < 0)
		{
			perror("\nsocket error\n");
			return 0;
		}
	
		bzero(&servaddr,sizeof(servaddr));
		servaddr.sin_family=AF_INET;
		servaddr.sin_addr.s_addr=INADDR_ANY;
		servaddr.sin_port=htons(5000);
		connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	
		printf("\nHttp Request:");
		
		printf("\nRequest type:");
		scanf("%s",&buffer);
		write(sockfd,buffer,sizeof(buffer));
	
		printf("URL:");
		scanf("%s",&buff);
		write(sockfd,buffer,sizeof(buffer));
	
		printf("Version:");
		scanf("%s",&buff);
		write(sockfd,buffer,sizeof(buffer));
	
		read(sockfd,buffer,sizeof(buffer));
		printf("Response status: %s\n",buffer);
	
		while(1)
		{
			read(sockfd,buffer,sizeof(buffer));
			if(strcmp(buffer,"end")==0) break;
				else printf("%s",buff);
		}
	
		printf("\nReceived requested data.\n");
		close(sockfd);
}
