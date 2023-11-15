#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>

int main(){

    int sd,bd;

    char buff[1024];
    char message[]="command executed successfully";
    
    struct sockaddr_in cliaddr,servaddr;
    bzero(&servaddr,sizeof(servaddr));

    socklen_t clilen = sizeof(cliaddr);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    sd = socket(AF_INET,SOCK_DGRAM,0);
    printf("socket created...\n");
    
    bd=bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    printf("binded successfully...\n");

    while(1){
        bzero(&buff,sizeof(buff));
        recvfrom(sd,buff,sizeof(buff),0,(struct sockaddr*)&cliaddr,&clilen);

        system(buff);

        sendto(sd,message,sizeof(message),0,(struct sockaddr*)&cliaddr,clilen);
    }

}