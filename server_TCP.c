/****************** SERVER CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int server_socket, new_client_socket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  //struct sockaddr_storage serverStorage;
  //socklen_t addr_size;

  /*---- Create the socket. The three arguments are: ----*/
  /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  
  /*---- Configure settings of the server address struct ----*/
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;
  /* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(7891);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // INADDR_ANY is a constant that sets the IP address to 0.0.0.0
 
  /* Set all bits of the padding field to 0 */
  // memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
 
  /*---- Bind the address struct to the socket ----*/
  bind(server_socket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  /*---- Listen on the socket, with 5 max connection requests queued ----*/
  if(listen(server_socket,5)==0)
    printf("Listening\n");
  else
    printf("Error\n");

  /*---- Accept call creates a new socket for the incoming connection ----*/
  //addr_size = sizeof serverStorage;
  /*---- To get the address of the client connection. It is optional. ----*/
  //new_client_socket = accept(server_socket, (struct sockaddr *) &serverStorage, &addr_size);
  
  new_client_socket = accept(server_socket,NULL,NULL);

  /*---- Send message to the socket of the incoming connection ----*/
  strcpy(buffer,"You have received a message from the server. ");
  send(new_client_socket,buffer,sizeof(buffer),0);

  return 0;
}