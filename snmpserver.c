#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
char hostid[100][1024], errorid[100][1024], errdet[100][1024];
int main()
{
	socklen_t len;
	int n,i,sockfd;
	struct sockaddr_in servaddr,cliaddr;
	char buffer[1024];
	
		sockfd=socket(AF_INET,SOCK_DGRAM,0);
		bzero(&servaddr,sizeof(servaddr));
		servaddr.sin_family=AF_INET;
		servaddr.sin_addr.s_addr=INADDR_ANY;
		servaddr.sin_port=htons(5000);
		bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
		
		printf("\nEnter number of hosts: ");
		scanf("%d",&n);
		printf("\nEnter status on every host: ");
		for(i=0;i<n;i++)
		{
			printf("\nFor host %d",i);
			printf("\nHost ID:");
			scanf("%s",&hostid[i]);
			printf("\nError ID:");
			scanf("%s",&errorid[i]);
			printf("\nError Details:");
			scanf("%s",errdet[i]);
		}
	
		len=sizeof(cliaddr);
		
		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&cliaddr,&len);
		printf("\nRequested for Host ID: %s\n",buff);
	
	int temp=-1;
	
		for(i=0;i<n;i++)
		{
			if(strcmp(hostid[i],buff)==0) temp=i;
		}
		if(temp==-1)
		{
			strcpy(buff,"No such host found.");
			sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&cliaddr,len);
		}
		else
		{
			strcpy(buffer,errorid[temp]);
			sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&cliaddr,len);
			strcpy(buffer,errdet[temp]);
			sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&cliaddr,len);
		}
		close(sockfd);
		return 0;
}
