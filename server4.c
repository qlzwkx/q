// UDP SERVER
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<netinet/in.h>

int main(){

    int sd, bd ;

    char buff[1024];
    char buffc[1024];

    struct sockaddr_in cliaddr,servaddr;
    bzero(&servaddr,sizeof(servaddr));

    socklen_t clilen = sizeof(cliaddr);

    servaddr.sin_family = AF_INET ;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    sd = socket(AF_INET,SOCK_DGRAM,0);
    printf("socket creeated successfully...\n");

    bd=bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    printf("binded successfully... \n");



    while(1){

        bzero(&buffc,strlen(buffc));
        recvfrom(sd,buffc,sizeof(buffc),0,(struct sockaddr*)&cliaddr,&clilen);
        printf("Client : %s \n",buffc);
        printf("Server: ");
        fgets(buff,sizeof(buff),stdin);
        sendto(sd,buff,sizeof(buff),0,(struct sockaddr*)&cliaddr,clilen);

    }

}