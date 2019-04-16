#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>
#include<stdlib.h>

main()//int argc,char *argv[])
{
 int sockfd,w;
 struct sockaddr_in serveraddress;
 unsigned short server_port=25051;
 char server_ip[] = "127.0.0.1",buffer[10]="Hello";
 bzero(&serveraddress,sizeof(serveraddress));
 serveraddress.sin_family=AF_INET;
 serveraddress.sin_port=htons(server_port);
 inet_aton(server_ip,(&serveraddress.sin_addr));
 if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
  {
   printf("Socket Error");
   exit(1);
  }
 printf("CLIENT: Socket Created");
 if((connect(sockfd,(struct sockaddr*)&serveraddress,sizeof(serveraddress)))<0)
  {
   printf("\nConnect Error\n");
   close(sockfd);
   exit(1);
  }
 //printf("\nCLIENT: Connected to the server %s",inet_ntoa(serveraddress.sin_addr));
 if((w=write(sockfd,buffer,sizeof(buffer)))<0)
  {
   printf("\nWrite Error\n");
   close(sockfd);
   exit(1);
  } 
 printf("\nCLIENT: %d bytes sent to the server\n",w);
 close(sockfd);
 exit(1);
}
