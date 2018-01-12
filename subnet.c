#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>>
void main()
{
	int ip[4],subip[4],networks[20];
	int i,mn,submask;
	int ptr=0,ctr=0;
	char ipstr[16];

		for(i=0;i<4;i++)
		{ip[i]=0;}

		printf("Enter ip address: ");
		scanf("%s",&ipstr);

		//converting string to integer ip
		while(ptr<4)
		{
			if(ipstr[ctr]=='.'||ipstr[ctr]=='\0')
			{
				ptr++;
				ctr++;
			}
			else
			{
				ip[ptr]=ip[ptr]*10+(ipstr[ctr]-'0');
				ctr++;
			}
		}

		//	printf("ip address = %d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);
		printf("\nEnter the shorthand of subnet mask: ");
		scanf("%d",&submask);

	int bit=1,mncount=0;
		ctr=0;
		printf("Subnet mask ip: ");
		while(ctr<32)
		{
			if(ctr%8==0&&ctr>1)
			{printf(".");}

			if(ctr<submask)
			{printf("1");}
			else
			{
				printf("0");
				mncount++; //to calculate the magic number
			}
			ctr++;
		}

		printf("\n");
		mn=pow(2,mncount);

	int netcount;
		netcount=256/mn;
		printf("There are %d subnets.",netcount);
		networks[0]=0;

		for(i=0;i<netcount;i++)
		{
			printf("\nFor subnet %d",i);
			printf("\nStarting host address:\t%d.%d.%d.%d",ip[0],ip[1],ip[2],mn*i);
			networks[i+1]=mn*(i+1);
			printf("\nBroadcast address:\t%d.%d.%d.%d\n",ip[0],ip[1],ip[2],((mn*(i+1))-1));
		}

		for(i=0;i<netcount;i++)
		{
			if(ip[3]==(networks[i+1]-1))
			{
			printf("It is a broadcast IP address of subnet %d",i);
			break;
			}
				else if(ip[3]>=networks[i] && ip[3]<networks[i+1])
				{
					printf("The entered IP address belongs to subnet %d",i);
					break;
				}
		}
}
