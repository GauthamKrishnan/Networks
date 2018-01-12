#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
int main()
{
	socklen_t len;
	int sockfd,n;
	char buffer[1024];
	struct sockaddr_in servaddr;
	
		sockfd=socket(AF_INET,SOCK_DGRAM,0);
		bzero(&servaddr,sizeof(servaddr));
		servaddr.sin_family=AF_INET;
		servaddr.sin_addr.s_addr=INADDR_ANY;
		servaddr.sin_port=htons(5000);
	
		len=sizeof(servaddr);

		printf("\nEnter a Host ID:");
		scanf("%s",&buffer);
		sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&servaddr,len);
		
		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&servaddr,&len);
		printf("\n Error ID for the given host: %s",buff);
		
		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&servaddr,&len);
		printf("\n Error Details for the given host: %s\n",buff);
		
		close(sockfd);
		return 0;
}

