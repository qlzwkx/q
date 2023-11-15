//CONCURRENT TCP IP DATE AND TIME 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<unistd.h>
#include<time.h>

int main(){

int sd,bd,ad;

char buff[1024];

struct sockaddr_in cliaddr, servaddr;
bzero(&servaddr,sizeof(servaddr));

socklen_t clilen = sizeof(cliaddr);

servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(2000);
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

sd=socket(AF_INET,SOCK_STREAM,0);
printf("Socket created ... \n");

bd = bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
printf("binding done... \n");

listen(sd,5);

ad=accept(sd,(struct sockaddr*)&cliaddr,&clilen);
printf("client connected ... \n");

bzero(&buff,sizeof(buff));
printf("recieved a request request from client \n");
time_t currentTime ;
currentTime = time(&currentTime);
send(ad,ctime(&currentTime),100,0);
printf("response sent to client\n ");

return 0;
}