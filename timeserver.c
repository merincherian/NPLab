//Client Server Communication using TCP
//SERVER
//TIME SERVER
//AUTHOR:AISWARYA M
//ROLL NO 7

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
int main()
{
         char sendMessage[1024] ,receiveMessage[1024];
         int sock, connected, result;        
         struct sockaddr_in serverAdd, clientAdd;   
         int length;
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)//socket creation
        {
            perror("Socket creation is failed");//error in socket creation
            exit(1);
        }   
        serverAdd.sin_family = AF_INET;        
        serverAdd.sin_port = htons(5000);
	serverAdd.sin_addr.s_addr = INADDR_ANY;
        bzero(&(serverAdd.sin_zero),8);
        if (bind(sock, (struct sockaddr *)&serverAdd, sizeof(struct sockaddr))== -1)//binding server to socket
        {
            perror("Unable to bind");
            exit(1);
        }
        if (listen(sock, 3) == -1)
        {
            perror("Listen");
            exit(1);
        }
        printf("Server Waiting for client connection\n");
        fflush(stdout);
        while(1)
        { 
		length = sizeof(struct sockaddr_in);
            	connected = accept(sock,(struct sockaddr *)&clientAdd,&length);
            	printf("Server is connected with IP address %s and port %d    \n",inet_ntoa(clientAdd.sin_addr),ntohs(clientAdd.sin_port));
			result = recv(connected,receiveMessage,512,0);
			receiveMessage[result] = '\0';
			printf("Received time is : %s \n" , receiveMessage);
                        fflush(stdout);
        }      
        return 0;
}
//OUTPUT
/*Server Waiting for client connection
Server is connected with IP address 127.0.0.1 and port 45768    
Received time is : Sat Apr 27 15:05:44 2019
*/
 
