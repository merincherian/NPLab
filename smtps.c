//SMTP
//SERVER PROGRAM
//AUTHOR:AISWARYA M
//ROLL NO 7

#include"sys/socket.h"
#include"netinet/in.h"
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int main()
{
char buf[100],domain[20],snd[25];
int k,i=0,j,m=0;
socklen_t len;
int sock_desc,temp_sock_desc;
struct sockaddr_in server,client;
memset(&server,0,sizeof(server));//setting memory
memset(&client,0,sizeof(client));
sock_desc=socket(AF_INET,SOCK_DGRAM,0);//socket creation
if(sock_desc==-1)
{
printf("\nError in socket creation");
exit(1);
}
server.sin_family=AF_INET;
server.sin_addr.s_addr=INADDR_ANY;
server.sin_port=3500;
k=bind(sock_desc,(struct sockaddr*)&server,sizeof(server));
if(k==-1)
{
printf("\nError in binding");
exit(1);
}
len=sizeof(server);
k=recvfrom(sock_desc,buf,sizeof(buf),0,(struct sockaddr*)&server,&len);//receive from socket
if(k==-1)
{
printf("\nError in receiving");
exit(1);
}
strcpy(snd,buf);
while(i<(strlen(buf)))
{
if(buf[i]=='@')
{
for(j=i+1;j<strlen(buf);j++)
domain[m++]=buf[j];
break;
}
i++;
}
printf("Receiving Mail...");
printf("\nDomain verified << %s >>",domain);
len=sizeof(server);
k=recvfrom(sock_desc,buf,sizeof(buf),0,(struct sockaddr*)&server,&len);
if(k==-1)
{
printf("\nError in receiving");
exit(1);
}
//receiving various details of mail from client
printf("\nFROM: %s\n",buf);
len=sizeof(server);
k=recvfrom(sock_desc,buf,sizeof(buf),0,(struct sockaddr*)&server,&len);
if(k==-1)
{
printf("\nError in receiving");
exit(1);
}
printf("\nSUBJECT: %s\n",buf);
printf("\nMSG BODY: \n\t");
len=sizeof(server);
k=recvfrom(sock_desc,buf,sizeof(buf),0,(struct sockaddr*)&server,&len);
if(k==-1)
{
printf("\nError in receiving");
exit(1);
}
while(strcmp(buf,".")!=0)
{
printf("%s\n\t",buf);
len=sizeof(server);
k=recvfrom(sock_desc,buf,sizeof(buf),0,(struct sockaddr*)&server,&len);
if(k==-1)
{
printf("\nError in receiving");//receive error
exit(1);
}
}
printf("\nMail received successfully from %s\n",snd);
close(temp_sock_desc);//close the socket
exit(0);
return 0;
}

//OUTPUT
/*Receiving Mail...
Domain verified <<  >>
FROM: AISWARYA

SUBJECT: VACATION

MSG BODY:hey you free during summer
	
Mail received successfully from ANAGHA
*/
