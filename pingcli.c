//Ping client
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h> 
#include<time.h> 
int main()
{
	int sockfd;
	char buffer[1024],buff[100];
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

	int ptr=0;
	struct timespec ts;
	long double tot=0;
		
		strcpy(buffer,"ping message"); 
		while(ptr<10)
		{
			ptr++;
			long double ans=0; 

				timespec_get(&ts, TIME_UTC);
				strftime(buff, sizeof(buff), "%D %T", gmtime(&ts.tv_sec)); 
				ans=ts.tv_nsec+ts.tv_sec*1e9;

				write(sockfd,buffer,sizeof(buffer));
				read(sockfd,buffer,sizeof(buffer)); 
				
				timespec_get(&ts, TIME_UTC);
				strftime(buff, sizeof(buff), "%D %T", gmtime(&ts.tv_sec)); 
				ans=-ans+ts.tv_nsec+ts.tv_sec*1e9;

				tot+=ans;
				ptrintf("RTT for Packet %d is %0.12Lf ns\n",ptr,ans);
		}
		tot/=10;
		printf("\n\nAverage RTT is %0.12Lf ns\n",tot); 

		close(sockfd);
		return 0;
}
