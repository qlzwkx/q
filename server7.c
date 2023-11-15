// fULL DUPLEX CHAT USING TCP IP 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>

int main()
{
    int sd,bd,ad;

    char buff[1024];
    char buffc[1024];
    pid_t cpid;

    struct sockaddr_in cliaddr,servaddr;
    bzero(&servaddr,sizeof(servaddr));

    socklen_t clilen = sizeof(cliaddr);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    sd=socket(AF_INET,SOCK_STREAM,0);
    printf("socket created successfully\n");

    bd=bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    printf("binding successfullll.....\n");

    listen(sd,3);
    printf("server is listining ...\n");

    ad=accept(sd,(struct sockaddr*)&cliaddr,&clilen);
    printf("connected...\n");

    cpid=fork();

    if(cpid==0){
        while(1){
            bzero(&buffc,sizeof(buffc));
            recv(ad,buffc,1024,0);
            printf("client : %s \n",buffc);
        }
    }
    else{
        while(1){
            // printf("enter text : ");
            fgets(buff,1024,stdin);
            send(ad,buff,1024,0);
            printf("\nmessage sent \n");
        }
    }



return 0 ;

}
