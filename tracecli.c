//Traceroute Client
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h> 
int main()
{
	int sockfd;
	char buffer[1024];
	struct sockaddr_in servaddr; 

		sockfd=socket(AF_INET,SOCK_STREAM,0); 
		if(sockfd<0)
		{
			perror("Socker error"); 
			return 0;
		}

		bzero(&servaddr,sizeof(servaddr)); 
		servaddr.sin_family=AF_INET; 
		servaddr.sin_addr.s_addr=INADDR_ANY; 
		servaddr.sin_port=htons(5000);
		connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr)); 

		printf("Enter source and destination : ");
		gets(buffer);
		write(sockfd,buffer,sizeof(buffer));

		while(1)
		{
			read(sockfd,buffer,sizeof(buffer));
			if(strcmp(buffer,"bye")==0)
			{
				printf("Server terminated the connection\n"); 
				break;
			}

			printf("Server : %s\n",buffer); 
			
			if(buffer[0]=='N') printf("Hop count : -\n");
				else printf("Hop count : %d\n",(strlen(buffer)+1)/2-1); 

			printf("Enter source and destination : ");
			gets(buffer);
			if(strcmp(buffer,"bye")==0)
			{
				write(sockfd,buffer,sizeof(buffer)); 
				printf("You terminated the connection\n"); 
				break;
			}
			write(sockfd,buffer,sizeof(buffer));
		}

		close(sockfd); 
		return 0;
}
