/*

Socket programming using TCP for communication between server and client

*/
//TCP Server
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <arpa/inet.h>

int main()
{
    struct sockaddr_in client,server;
    int s,n,sock;
    char b1[100] = "",b2[100]="2kBcs.tk";
    s = socket(AF_INET,SOCK_STREAM,0);
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = 5000;

    bind(s, (struct sockaddr *)&server,sizeof(server));
    printf("listening..");
    printf("\n Server ready, waiting for client ");
    listen(s,1);

    n = sizeof(client);
    sock = accept(s,(struct sockaddr *)&client , &n);
    
    for(;;)
    {
        recv(sock,b1,sizeof(b1),0);
        if(strcmp(b1,"bye")==0)
        break;
        printf("\n client : %s",b1);
 
        printf("\n server : ");
        gets(b2);
        send(sock,b2,sizeof(b2),0);
        if(strcmp(b2,"bye") == 0)
        break;

    }
    close(sock);
    close(s);
return 0;
}