// R6 MINI AISHWARYA
// EXPERIMENT 11 - TIME SERVER APPLICATION USING UDP

/*---------SERVER SIDE----------*/

#include"sys/socket.h"
#include"netinet/in.h"
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"time.h"

int main()
{
	const time_t t=time(NULL);
	char buf[100];
	int k,len;
	int sock_desc,connfd;
	struct sockaddr_in serv,cli;
	memset(&serv,0,sizeof(serv));
	sock_desc=socket(AF_INET,SOCK_DGRAM,0); //creating the socket DGRAM: connectionless/UDP
	if(sock_desc==-1)
	{
		printf("Error in socket creation");
		exit(1);
	}
	//setting server parameters:family,address,port
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv.sin_port=htons(3031);	
	if ((bind(sock_desc,(struct sockaddr*)&serv,sizeof(serv))) != 0)//binding the socket to the address
	{         
		printf("socket bind failed...\n"); 
	        exit(0); 
    	} 
    	else
        	printf("Socket successfully binded\n"); 
	len=sizeof(cli);
	bzero(buf,sizeof(buf)); // similar to memset
	recvfrom(sock_desc, (char *)buf, 1024,  MSG_WAITALL, ( struct sockaddr *) &cli,&len);//receive data from client
	bzero(buf,sizeof(buf)); 
	snprintf(buf,sizeof(buf),"%24s\r\n",ctime(&t));	//time format
	sendto(sock_desc, buf, strlen(buf),MSG_CONFIRM, (const struct sockaddr *) &cli,sizeof(cli));//sedning time
	printf("\nTime sent");
	return 0;	
}



/*



OUTPUT:
_______

Socket successfully binded

Time sent



*/

