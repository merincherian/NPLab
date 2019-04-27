// R6 MINI AISHWARYA
// EXPERIMENT 11 - TIMER SERVER APPLICATION USING UDP

#include"sys/socket.h"
#include"netinet/in.h"
#include"stdio.h"
#include"string.h"
#include"stdlib.h"

int main()
{
	char buf[100];
	int k,n,len;
	int sock_desc;
	struct sockaddr_in serv;
	memset(&serv,0,sizeof(serv));
	sock_desc=socket(AF_INET,SOCK_DGRAM,0);//creating the socket DGRAM: connectionless/UDP
	if(sock_desc==-1)
	{
		printf("Error in socket creation");
		exit(1);
	}
	//setting server parameters:family,address,port
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv.sin_port=htons(3031);
	strcpy(buf,"Give time");
	len=sizeof(serv);
	bzero(buf, sizeof(buf));
	sendto(sock_desc, buf, strlen(buf),MSG_CONFIRM, (const struct sockaddr *) &serv,sizeof(serv));//sending the input data
	printf("\nTime Request sent");
	recvfrom(sock_desc, (char *)buf, 1024,  MSG_WAITALL, ( struct sockaddr *) &serv,&len);
	printf("\n%s",buf);
	return(0);
}



/*



OUTPUT:
_______

Time Request sent
Thu Apr 25 10:42:04 2019



*/

