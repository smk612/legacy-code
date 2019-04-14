#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>

#define RECVBUFSIZE 1024

main()
{
	int servSock, recvBufSize,res;
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;
	char server_ip[] = "127.0.0.1";
	unsigned short server_port=25051;
	char recvBuf[RECVBUFSIZE],sendBuf[RECVBUFSIZE];
	bzero(&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;//Internet Address family
	serverAddr.sin_port = htons(server_port);//Local Port address
	inet_aton(server_ip,(&serverAddr.sin_addr));
	if((servSock=socket(AF_INET,SOCK_DGRAM,0))<0)//DGRAM as UDP uses DGRAM
	{
		printf("\n\tSocket Error.\n");
		exit(1);
	}
	printf("\n\tSERVER: Socket Created.\n");
	if((bind(servSock,(struct sockaddr*)&serverAddr, sizeof(serverAddr)))<0)//-1 indicates failure
	{
		printf("\n\tBind Error.\n");
		close(servSock);//Closing the socket
		exit(1);
	}
	printf("\n\tSERVER: Binded Successfully.\n");
	while(1)
	{
		addr_size = sizeof(serverStorage);
		if(recvBufSize=recvfrom(servSock,recvBuf,RECVBUFSIZE,0,(struct sockaddr *)&serverStorage, &addr_size)<0)
		{
			printf("\n\tReceive Error.\n");
		}
		res=atoi(recvBuf);
		sprintf(sendBuf,"\nNumber of months and days converted : %d months %d days\n", (res/30), (res%30));
		if(sendto(servSock,sendBuf,sizeof(sendBuf),0,(struct sockaddr *)&serverStorage,addr_size)<0)
		{
			printf("\n\tSend Error.\n");
			exit(1);
		}
	}
}
