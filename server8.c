// implementation of ftp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

int main()
{
    int sd, bd, ad;

    char buff[1024];
    char filebuff[1024];

    FILE *fp ;

    struct sockaddr_in cliaddr,servaddr;
    bzero(&servaddr,sizeof(servaddr));

    socklen_t clilen = sizeof(cliaddr);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    sd = socket(AF_INET,SOCK_STREAM,0);
    printf("socket created...\n");

    bd=bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    printf("Binding done successfulllllly..\n");

    listen(sd,3);

    ad = accept(sd,(struct sockaddr*)&cliaddr,&clilen);
    printf("connected ... \n");

    while(1){
        bzero(&buff,sizeof(buff));
        bzero(&filebuff,sizeof(filebuff));

        recv(ad,buff,sizeof(buff),0);

        fp = fopen(buff,"r");

        fread(filebuff,sizeof(filebuff),2,fp);

        send(ad,filebuff,sizeof(filebuff),0);
        printf("\n data sent !! \n");

    }

    return 0;

}
