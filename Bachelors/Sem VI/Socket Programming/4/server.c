#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>

#define MAXPENDING 5
#define RECVBUFSIZE 20

main()
{
	int servSock, clientAddrLen, clientSock, recvBufSize,i;
	float res;
	struct sockaddr_in clientAddr,serverAddr;
	char server_ip[] = "127.0.0.1";
	unsigned short server_port=25051;
	char recvBuf[RECVBUFSIZE];
	bzero(&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;//Internet Address family
	serverAddr.sin_port = htons(server_port);//Local Port address
	inet_aton(server_ip,(&serverAddr.sin_addr));
	if((servSock=socket(AF_INET,SOCK_STREAM,0))<0)
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
	if(listen(servSock,MAXPENDING)<0)//-1 indicates failure
	{
		printf("\n\tListen Error.\n");
		close(servSock);//Closing the socket
		exit(1);
	}
	printf("\n\tSERVER: Listening to Clients..\n\tPress Ctrl+C to stop the server.\n");
	while(1)//Run forever
	{
		clientAddrLen = sizeof(clientAddr);
		if((clientSock=accept(servSock,(struct sockaddr *)&clientAddr,&clientAddrLen))<0)
		{
			printf("\n\tAccept Error.\n");
			close(servSock);
			exit(1);
		}
		for(i=0;i<4;i++)
		{
			if(recvBufSize=recv(clientSock,recvBuf,RECVBUFSIZE,0)<0)
			{
				printf("\n\tReceive Error.\n");
			}
			else
			{
				if(i==0)
					printf("\n\tUser Name:%s",recvBuf);
				else if(i==1)
					printf("\n\tUser Age:%s",recvBuf);
				else if(i==2)
					printf("\n\tUser DOB(DD/MM/YYYY):%s",recvBuf);
				else
					printf("\n\tUser Percentage:%s",recvBuf);
				printf("\n");
			}
		}
		close(clientSock);
		continue;
		close(clientSock);
	}
	close(servSock);
}
