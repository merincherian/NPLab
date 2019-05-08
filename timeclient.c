//Client Server Communication using TCP 
//client process
//TIME SERVER
//AUTHOR AISWARYA M
//ROLL NO 7

#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
int main()
{
	const time_t t=time(NULL);
        char sendMessage[512],receiveMessage[512];
	int sock, result;
	struct hostent *host;
	struct sockaddr_in serverAdd; 
	host = gethostbyname("127.0.0.1"); 
	//Setting socket    
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
 	{
            	perror("Socket creation failed");
		exit(1);
        }
        serverAdd.sin_family = AF_INET;    
        serverAdd.sin_port = htons(5000);  
        serverAdd.sin_addr = *((struct in_addr *)host->h_addr);
        bzero(&(serverAdd.sin_zero),8);
        if (connect(sock, (struct sockaddr *)&serverAdd, sizeof(struct sockaddr)) == -1)
        {
            perror("Connection failed");
            exit(1);
        }
        
		snprintf(sendMessage,sizeof(sendMessage),"%24s\r\n",ctime(&t));
        	printf("\nTIME SEND \n ");
        	send(sock,sendMessage,strlen(sendMessage), 0);
        return 0;
}
//OUTPUT
/*TIME SEND*/
