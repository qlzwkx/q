// HALF DUPLEX CHAT USIING TCP IP
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>

int main(){

    int sd , bd , ad ;

    char buff[1024] ;
    char buffc[1024] ;

    struct sockaddr_in cliaddr , servaddr ;
    bzero(&servaddr,sizeof(servaddr));

    socklen_t clilen = sizeof(cliaddr);

    servaddr.sin_family = AF_INET ;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    sd=socket(AF_INET,SOCK_STREAM,0);
    printf("socket created ...\n");

    bd = bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    printf("binding done...\n");

    listen(sd,5);

    ad=accept(sd,(struct sockaddr*)&cliaddr,&clilen);
    printf("connected...");

    while(1){
        bzero(&buffc,sizeof(buffc));
        recv(ad,buffc,sizeof(buffc),0);
        printf("CLIENT : %s \n",buffc);
        printf("Enter Message  To Send : ");
        fgets(buff,1000,stdin);
        send(ad,buff,sizeof(buff),0);
        printf("\nmessage sent...");
    }



return 0 ;

}
