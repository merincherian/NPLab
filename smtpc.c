//SMTP
//CLIENT PROGRAM
//AUTHOR : AISWARYA M
//ROLL NO: 7
#include"sys/socket.h"
#include"netinet/in.h"
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int main()
{
char buf[100];
int k;
int sock_desc;
struct sockaddr_in client;
memset(&client,0,sizeof(client));
sock_desc=socket(AF_INET,SOCK_DGRAM,0);//socket creation
if(sock_desc==-1)
{
printf("\nError in socket creation");
exit(1);
}
client.sin_family=AF_INET;
client.sin_addr.s_addr=inet_addr("127.0.0.1");
client.sin_port=3500;
printf("\nMAIL TO : ");
gets(buf);
k=sendto(sock_desc,buf,sizeof(buf),0,(struct sockaddr*)&client,sizeof(client));//sending to socket the receiver
if(k==-1)
{
printf("\nError in sending");
exit(1);
}
strcpy(buf,"\0");
printf("\nFROM : ");
gets(buf);
k=sendto(sock_desc,buf,sizeof(buf),0,(struct sockaddr*)&client,sizeof(client));//sending to socket the sender
if(k==-1)
{
printf("\nError in sending");
exit(1);
}
strcpy(buf,"\0");
printf("\nSUBJECT : ");
gets(buf);
k=sendto(sock_desc,buf,sizeof(buf),0,(struct sockaddr*)&client,sizeof(client));//sending to socket the subject
if(k==-1)
{
printf("\nError in sending");
exit(1);
}
strcpy(buf,"\0");
printf("\nMSG BODY : ");
while(strcmp(buf,".")!=0)
{
strcpy(buf,"\0");
gets(buf);
//sending message body
k=sendto(sock_desc,buf,sizeof(buf),0,(struct sockaddr*)&client,sizeof(client));
if(k==-1)
{
printf("\nError in sending");
exit(1);
} }
close(sock_desc);//close socket
return 0;
}

//OUTPUT
/*MAIL TO : ANAGHA

FROM : AISWARYA

SUBJECT : VACATION

MSG BODY : hey you free during summer
*/
