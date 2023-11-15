// arp implementation 

#include<stdio.h>
#include<sys/types.h>
#include<complex.h>
#include<sys/ioctl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<math.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netinet/if_ether.h>
#include<net/ethernet.h>
#include<netdb.h>
#include<arpa/inet.h>

int main(){
    int s=socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in sin={0};
    struct arpreq myarp={{0}};
    unsigned char*ptr;
    sin.sin_family = AF_INET;
    char ip[20];
    printf("enter ip :");
    scanf("%s",ip);
    memcpy(&myarp.arp_pa,&sin,sizeof(myarp.arp_pa));
    strcpy(myarp.arp_dev,"echo");
    ptr=&myarp.arp_pa.sa_data[0];
    printf("mac address is:");
    printf("%p:%p:%p:%p:%p:%p",ptr,(ptr+1),(ptr+2),(ptr+3),(ptr+4),(ptr+5));


    return 0;

}

