#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
	socklen_t len;
	int sockfd,connfd,n;
	struct sockaddr_in servaddr,cliaddr;
 	char buff[1024];

	sockfd=socket(AF_INET,SOCK_STREAM,0); 
	if(sockfd < 0)
	{
		perror("\nunable to create socket\n\n"); 
		return 0;
	}

	bzero(&servaddr,sizeof(servaddr)); 
	servaddr.sin_family=AF_INET; 
	servaddr.sin_addr.s_addr=INADDR_ANY; 
	servaddr.sin_port=htons(5000);
	bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)); listen(sockfd,0);
	
	len=sizeof(cliaddr);
	connfd=accept(sockfd,(struct sockaddr*)&cliaddr,&len); 
	n=read(connfd,buff,sizeof(buff));
	printf("Message Received :%s",buff); write(connfd,buff,sizeof(buff)); 

	close(connfd);

	return 0;
}
