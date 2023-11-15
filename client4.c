// UDP - CLIENT 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>

int main()
{
   int sd;
   
   char buff[1024];
   char buffs[1024];

   struct sockaddr_in cliaddr,servaddr;
   bzero(&servaddr,sizeof(servaddr));
   
   socklen_t servlen = sizeof(servaddr);
   
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(2000);
   servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
   
   sd = socket(AF_INET,SOCK_DGRAM,0);
   printf("client socket created\n");
   
   
   
   while(1)
   {
   	printf("Enter text : ");
   	fgets(buff,100,stdin);
   	sendto(sd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
   	recvfrom(sd,buffs,sizeof(buffs),0,(struct sockaddr*)&servaddr,&servlen);
   	printf("Server : %s\n",buffs);
   }
   	return 0;
  }