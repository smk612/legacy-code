#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 1024

main()
{
	int clientSock,r;
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	char server_ip[] = "127.0.0.1";
	unsigned short server_port=25051;
	char sendBuf[BUFSIZE], recvBuf[BUFSIZE];
	printf("\n\tEnter number of days:\n\t");
	gets(sendBuf);
	bzero(&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;//Internet Address family
	serverAddr.sin_port = htons(server_port);//Local Port address
	inet_aton(server_ip,(&serverAddr.sin_addr));
	if((clientSock=socket(AF_INET,SOCK_DGRAM,0))<0)
	{
		printf("\n\tSocket Error.\n");
		exit(1);
	}
	printf("\n\tCLIENT: Socket Created.\n");
	addr_size=sizeof(struct sockaddr_in);
	if(sendto(clientSock,sendBuf,sizeof(sendBuf),0,(struct sockaddr *)&serverAddr,addr_size)<0)
	{
		printf("\n\tSend Error.\n");
		exit(1);
	}
	printf("\n\tCLIENT: Sent.\n");
	if((r=recvfrom(clientSock,recvBuf,sizeof(recvBuf),0,(struct sockaddr *)&serverAddr,&addr_size))<0)
    	{
     		printf("\nRead Error\n");
     		exit(1);
    	}
    	printf("%s",recvBuf);
	close(clientSock);
}
