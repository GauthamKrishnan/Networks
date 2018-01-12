#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
int main()
{
	socklen_t len;
	int sockfd,confd,i;
	char buff[1024];
	struct sockaddr_in servaddr,cliaddr;
	
		sockfd=socket(AF_INET,SOCK_STREAM,0);
		if(sockfd < 0) 
		{
			perror("\nUnable to create socket\n\n");
			return 0;
		}
	
		bzero(&servaddr,sizeof(servaddr));
		servaddr.sin_family=AF_INET;
		servaddr.sin_addr.s_addr=INADDR_ANY;
		servaddr.sin_port=htons(5000);
		if(bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
		{
			perror("\nBind error");
			return 0;
		}
	
		listen(sockfd,0);
		
		len=sizeof(cliaddr);
		confd=accept(sockfd,(struct sockaddr*)&cliaddr,&len);
		
		printf("\nRequest from Client:");

		read(confd,buff,sizeof(buff));
		printf("\nRequest type: %s",buff);
		
		read(confd,buff,sizeof(buff));
		printf("\nURL: %s",buff);
	
	int start=-1,j=0;
		for(i=0;buff[i]!='\0';i++)
		{
			if(buff[i]=='/')
			{
				start=i;
				break;
			}
		}
	char filename[20];
		for(i=start+1;buff[i]!='\0';i++)
		{
			filename[j]=buff[i];
			j++;
		}
		filename[j]='\0';
	
		read(confd,buff,sizeof(buff));
		printf("\nHTTP Version: %s",buff);
	
		strcpy(buff,"200:OK");
		write(confd,buff,sizeof(buff));
	
	FILE *fp = fopen(filename,"r");
		while(fgets(buff,500,fp)!=NULL)
		{write(confd,buff,sizeof(buff));}
	
		strcpy(buff,"end");
		write(confd,buff,sizeof(buff));
		
		printf("\nResponded to the request.\n");
		close(fp);
		close(sockfd);
		close(confd);
		return 0;
}
	
