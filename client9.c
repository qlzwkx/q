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

    int sd;

    char buffs[1024] , buff[1000];
    
    struct sockaddr_in cliaddr,servaddr;
    bzero(&servaddr,sizeof(servaddr));

    socklen_t servlen = sizeof(servaddr);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    sd = socket(AF_INET,SOCK_DGRAM,0);
    printf("socket created...\n");
    


    while(1){
        printf("enter command to execute remotely : ");
        scanf("%s",buffs);
        sendto(sd,buffs,sizeof(buff),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
        printf("data sent ! \n");
        recvfrom(sd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,&servlen);
        printf("UDP Server : %s",buff);
    }

}