/*

Socket programming using UDP for communication between server and client

*/
//UDP Client 
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
main()
{

	struct sockaddr_in client,server;
	int s,n;
	char b1[100],b2[100];

	s=socket(AF_INET,SOCK_DGRAM,0);
	server.sin_family=AF_INET;
	server.sin_port=2000;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");

	printf("\n  client ready.. ");
	n=sizeof server;
	
while(1)
{
	printf("\n client:  ");
	gets(b2);
	sendto(s,b2,sizeof b2,0,(struct sockaddr *)&server,n);
	if(strcmp(b2,"bye")==0)
	break;

	recvfrom(s,b1,sizeof b1,0,NULL,NULL);

	printf("\n server: %s ",b1);

	}

}
