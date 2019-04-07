#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 20

main()
{
	int clientSock;
	struct sockaddr_in serverAddr;
	char server_ip[] = "127.0.0.1";
	unsigned short server_port=25051;
	char sendBufName[BUFSIZE],sendBufAge[BUFSIZE],sendBufDOB[BUFSIZE],sendBufPer[BUFSIZE];
	printf("\n\tEnter User Details:\n\tName:");
	gets(sendBufName);
	printf("\tAge:");
	gets(sendBufAge);
	printf("\tDate of Birth(DD/MM/YYYY):");
	gets(sendBufDOB);
	printf("\tPercentage in 10+2 exam:");
	gets(sendBufPer);
	bzero(&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;//Internet Address family
	serverAddr.sin_port = htons(server_port);//Local Port address
	inet_aton(server_ip,(&serverAddr.sin_addr));
	if((clientSock=socket(PF_INET,SOCK_STREAM,0))<0)
	{
		printf("\n\tSocket Error.\n");
		exit(1);
	}
	printf("\n\tCLIENT: Socket Created.\n");
	if((connect(clientSock,(struct sockaddr*)&serverAddr,sizeof(serverAddr)))<0)
  	{
   		printf("\nConnect Error\n");
   		close(clientSock);
   		exit(1);
  	}
  	printf("\n\tCLIENT: Connected.\n");
  	if(write(clientSock,sendBufName,sizeof(sendBufName))<0)
	{
		printf("\n\tSend Error Name.\n");
		exit(1);
	}
	if(write(clientSock,sendBufAge,sizeof(sendBufAge))<0)
	{
		printf("\n\tSend Error Age.\n");
		exit(1);
	}
	if(write(clientSock,sendBufDOB,sizeof(sendBufDOB))<0)
	{
		printf("\n\tSend Error DOB.\n");
		exit(1);
	}
	if(write(clientSock,sendBufPer,sizeof(sendBufPer))<0)
	{
		printf("\n\tSend Error Percentage.\n");
		exit(1);
	}
	printf("\n\tCLIENT: Sent.\n");
	close(clientSock);
}
