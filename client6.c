// HALF DUPLEX CHAT USIING TCP IP
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

    int sd , cd ;

    char buff[1024];
    char buffs[1024];

    struct sockaddr_in cliaddr, servaddr;
    bzero(&servaddr,sizeof(servaddr));

    socklen_t clilen = sizeof(cliaddr);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    sd=socket(AF_INET,SOCK_STREAM,0);
    printf("socket created ...\n");

    cd=connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    printf("connected to server...\n");

    while(1){
        printf("enter text : ");
        fgets(buffs,1000,stdin);
        send(sd,buffs,sizeof(buffs),0);
        recv(sd,buff,sizeof(buff),0);
        printf("server : %s",buff);
    }

    return 0 ;

}