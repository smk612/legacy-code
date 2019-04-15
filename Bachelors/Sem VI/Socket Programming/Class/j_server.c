#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<strings.h>

main()//int argc,char *argv[])
{
 int sockfd,r,acceptfd,clientaddrlen;
 char recvbuf[10];
 unsigned short server_port=25051;
 char server_ip[] = "127.0.0.1";
 struct sockaddr_in serveraddress,clientaddress;
 bzero(&serveraddress, sizeof(serveraddress));
 serveraddress.sin_family=AF_INET;
 serveraddress.sin_port=htons(server_port);
 inet_aton(server_ip,(&serveraddress.sin_addr));
 //inet_aton(server_ip,(&clientaddress.sin_addr));
 //serveraddress.sin_addr.s_addr=htonl(INADDR_ANY);
 if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
  {
   printf("\nSocket Error\n");
   exit(1);
  }
 printf("\nSERVER: Socket Created\n");
 if((bind(sockfd,(struct sockaddr*)&serveraddress,sizeof(serveraddress)))<0)
  {
   printf("\nBind Error\n");
   close(sockfd);
   exit(1);
  }
 printf("\nSERVER: Bind Successful\n");
 if((listen(sockfd,5))<0)
  {
   printf("\nListen Error\n");
   close(sockfd);
   exit(1);
  }
 clientaddrlen=sizeof(clientaddress);
 printf("\nSERVER: Listening to Clients.. Press Ctrl+C to stop the server.\n");
 while(1)
  {
   if((acceptfd=accept(sockfd,(struct sockaddr*)&clientaddress,&clientaddrlen))<0)
    {
     printf("\nAccept Error\n");
     close(sockfd);
     exit(1);
    }
   //printf("\nSERVER: Connection Request from Client %s accepted\n",inet_ntoa(clientaddress.sin_addr));
   if((r=read(acceptfd,recvbuf,sizeof(recvbuf)))<0)
    {
     printf("\nRead Error\n");
     exit(1);
    }
   printf("\nSERVER: Received %d bytes\n",r);
   recvbuf[r]='\0';
   puts(recvbuf);
  }
}
