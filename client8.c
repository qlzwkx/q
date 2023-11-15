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
    int sd, cd ;

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

    cd=connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    printf("connected  successfulllllly..\n");


    while(1){
       printf("enter file name :");
       scanf("%s",buff);
       send(sd,buff,sizeof(buff),0);
       printf("file name is send...\n");

       printf("data recieved from server : ");
       recv(sd,filebuff,sizeof(filebuff),0);
       printf("%s \n",filebuff);


    }

    return 0;

}
