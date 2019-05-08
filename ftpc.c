//FTP 
//CLIENT PROGRAM
//AUTHOR :AISWARYA M
//ROLL NO : 7

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/stat.h>
#include<sys/sendfile.h>
#include <fcntl.h>
int main(int arc,char *argv[])
{
	struct sockaddr_in address;
	int sock_descr;
	int k,choice,len,l,c=0,filehandle;
	char buf[100],length[100],fil[100],filename[100];
	memset(&address,0,sizeof(address));
	sock_descr=socket(AF_INET,SOCK_STREAM,0);//socket creation
	if(sock_descr==-1)
	{
		printf("socket creation failed");//socket creation error
		exit(1);
	}
	address.sin_family=AF_INET;
	address.sin_port=3003;
	address.sin_addr.s_addr=INADDR_ANY;
	k=connect(sock_descr,(struct sockaddr*)&address,sizeof(address));//socket connection
	if(k==-1)
	{
		printf("connecting failed");
		exit(1);
	}
	while(1)
	{
		printf("\n1:LIST\n2:LOAD\n3:Exit : ");//print list of choices
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				filehandle=open("list2.txt",O_RDWR|O_CREAT,0700);
				strcpy(buf,"LIST");
				k=send(sock_descr,buf,strlen(buf),0);//send to socket
				if(k==-1)
				{
					printf("send failed");//send failed
					exit(1);
				}
				k=recv(sock_descr,length,100,0);//receive from socket
				if(k==-1)
				{
					printf("receive failed");//receive failed
					exit(1);
				}
				len=atoi(length);
				while(c<len)
				{
					l=read(sock_descr,fil,100);
					if(l==0)
						break;
					write(filehandle,fil,100);
					c+=l;
				}
				system("cat list2.txt");
				close(filehandle);
				break;
			case 2://option 2
				filehandle=open("list3.txt",O_RDWR|O_CREAT,0700);
				strcpy(buf,"LOAD");
				printf("Enter filename : ");
				scanf("%s",filename);
				strcat(buf,filename);
				k=send(sock_descr,buf,strlen(buf),0);
				if(k==-1)
				{
					printf("send failed");
					exit(1);
				}	
				k=recv(sock_descr,length,100,0);
				if(k==-1)
				{
					printf("receive failed");
					exit(1);
				}
				len=atoi(length);
				c=0;
				while(c<len)
				{
					l=read(sock_descr,fil,strlen(fil));
					if(l==0)
						break;
					write(filehandle,fil,strlen(fil));
					c+=l;
				}
			system("cat list3.txt");
			break;
		case 3://option 3
			exit(0);//exit program
		default:
			break;
		}
	}
	return 0;
}
//OUTPUT
/*
1:LIST
2:LOAD
3:Exit : 1
total 416
drwxr-x--- 17 r6   r6    4096 Apr 27 16:21 .
drwxr-xr-x  9 root root  4096 Jan 17 15:20 ..
-rwxrwxr-x  1 r6   r6    7763 Apr  9 14:35 a.out
-rw-------  1 r6   r6   11580 Apr 27 16:22 .bash_history
-rw-r--r--  1 r6   r6     220 Jan 17 15:20 .bash_logout
-rw-r--r--  1 r6   r6    3637 Jan 17 15:20 .bashrc
drwx------ 15 r6   r6    4096 Apr  4 10:24 .cache
-rw-rw-r--  1 r6   r6     907 Feb 12 16:12 child.c
-rw-rw-r--  1 r6   r6     907 Feb 12 16:12 child.c~
-rw-rw-r--  1 r6   r6    1701 Feb 12 16:22 childmul.c
-rw-rw-r--  1 r6   r6    1701 Feb 12 16:22 childmul.c~
-rwxrwxr-x  1 r6   r6    7718 Apr 27 15:00 client
-rwxrwxr-x  1 r6   r6    7906 Apr 27 16:20 client.out
-rw-rw-r--  1 r6   r6    1227 Mar 21 12:13 client_tcp.c
drwx------  3 r6   r6    4096 Jan 29 16:26 .compiz
drwx------ 19 r6   r6    4096 Apr  4 10:42 .config
drwxr-xr-x  2 r6   r6    4096 Apr  9 15:34 Desktop
-rw-r--r--  1 r6   r6      25 Jan 29 15:19 .dmrc
drwxr-xr-x  2 r6   r6    4096 Jan 29 15:19 Documents
drwxr-xr-x  2 r6   r6    4096 Apr 27 15:04 Downloads
-rw-r--r--  1 r6   r6    8980 Jan 17 15:20 examples.desktop
-rw-rw-r--  1 r6   r6    2245 Apr 27 16:19 ftpc.c
-rw-rw-r--  1 r6   r6    2245 Apr 27 15:54 ftpc.c~
-rw-rw-r--  1 r6   r6    2405 Apr 27 16:20 ftps.c
-rw-rw-r--  1 r6   r6    2405 Apr 27 15:54 ftps.c~
-rw-rw-r--  1 r6   r6     189 Apr 12 11:33 func.html
drwx------  3 r6   r6    4096 Apr 27 14:35 .gconf
-rw-------  1 r6   r6    6840 Apr 27 14:35 .ICEauthority
-rw-rw-r--  1 r6   r6       0 Apr 27 15:59 lisst
-rw-rw-r--  1 r6   r6       0 Apr 27 16:04 list
-rwx------  1 r6   r6    5000 Apr 27 16:22 list2.txt
-rwx------  1 r6   r6    5100 Apr 27 16:20 list2.txt~
-rwx------  1 r6   r6       0 Apr 27 15:55 list3.txt
-rw-rw-r--  1 r6   r6       0 Apr 27 16:24 list.txt
drwx------  3 r6   r6    4096 Jan 29 15:19 .local
drwx------  5 r6   r6    4096 Jan 29 15:20 .mozilla
-rw-rw-r--  1 r6   r6    1020 Mar 19 16:22 msgq1.c
-rw-rw-r--  1 r6   r6    1020 Mar 19 16:22 msgq1.c~
-rw-rw-r--  1 r6   r6    1290 Mar 19 16:26 msgq.c
-rw-rw-r--  1 r6   r6    1290 Mar 19 16:22 msgq.c~
-rw-rw-r--  1 r6   r6    1240 Apr 27 14:55 mtcps.c
-rw-rw-r--  1 r6   r6    1240 Apr 27 14:45 mtcps.c~
-rw-rw-r--  1 r6   r6    1354 Apr 27 16:18 multiclient.c
-rw-rw-r--  1 r6   r6    1310 Apr 27 15:15 multiclient.c~
-rw-rw-r--  1 r6   r6    1464 Apr 27 16:18 multiserver.c
-rw-rw-r--  1 r6   r6    1440 Apr 27 15:16 multiserver.c~
-rw-rw-r--  1 r6   r6    1227 Apr 27 14:55 multitcpc1.c
-rw-rw-r--  1 r6   r6    1227 Apr 27 14:54 multitcpc1.c~
-rw-rw-r--  1 r6   r6    1244 Apr  9 16:02 multitcpc2.c
-rw-rw-r--  1 r6   r6    1244 Apr  9 15:53 multitcpc2.c~
-rw-rw-r--  1 r6   r6    1315 Apr  2 16:22 multitcps.c
-rw-rw-r--  1 r6   r6    1314 Apr  2 16:12 multitcps.c~
drwxr-xr-x  2 r6   r6    4096 Jan 29 15:19 Music
-rw-rw-r--  1 r6   r6     338 Apr 12 11:19 new.html
-rw-rw-r--  1 r6   r6     327 Apr 12 11:18 new.html~
drwxr-xr-x  2 r6   r6    4096 Jan 29 15:19 Pictures
drwx------  3 r6   r6    4096 Apr  4 10:24 .pki
-rw-r--r--  1 r6   r6     675 Jan 17 15:20 .profile
drwxr-xr-x  2 r6   r6    4096 Jan 29 15:19 Public
-rwxrwxr-x  1 r6   r6    7747 Apr  9 16:20 server
-rwxrwxr-x  1 r6   r6    8023 Apr 27 16:20 server.out
-rw-rw-r--  1 r6   r6    1326 Mar 21 12:13 server_tcp.c
-rw-rw-r--  1 r6   r6     905 Mar  5 15:10 shm1.c
-rw-rw-r--  1 r6   r6     905 Mar  5 15:10 shm1.c~
-rw-rw-r--  1 r6   r6     730 Mar  5 16:14 shm.c
-rw-rw-r--  1 r6   r6     699 Mar  5 15:08 shm.c~
-rw-rw-r--  1 r6   r6     693 Feb 14 11:30 single1.c
-rw-rw-r--  1 r6   r6     693 Feb 14 11:30 single1.c~
-rw-rw-r--  1 r6   r6     604 Feb 14 11:15 single.c
-rw-rw-r--  1 r6   r6     605 Feb 14 11:12 single.c~
-rw-rw-r--  1 r6   r6    1534 Apr 27 15:26 smtpc.c
-rw-rw-r--  1 r6   r6    1427 Apr 27 15:20 smtpc.c~
-rw-rw-r--  1 r6   r6    2150 Apr 27 15:26 smtps.c
-rw-rw-r--  1 r6   r6    1982 Apr 27 15:24 smtps.c~
-rw-rw-r--  1 r6   r6    1295 Apr  9 10:28 tab.html
-rw-rw-r--  1 r6   r6    1320 Apr  9 10:27 tab.html~
-rw-rw-r--  1 r6   r6    1064 Mar 21 11:22 tcp1.c
-rw-rw-r--  1 r6   r6    1102 Mar 21 11:43 tcp.c
-rw-rw-r--  1 r6   r6    1107 Mar 21 11:23 tcp.c~
-rw-rw-r--  1 r6   r6    1113 Apr  2 14:54 tcpclient.c
-rw-rw-r--  1 r6   r6    1113 Apr  2 14:54 tcpclient.c~
-rw-rw-r--  1 r6   r6    1198 Apr  2 14:55 tcpserver.c
-rw-rw-r--  1 r6   r6    1198 Apr  2 14:55 tcpserver.c~
drwxr-xr-x  2 r6   r6    4096 Jan 29 15:19 Templates
-rw-rw-r--  1 r6   r6    1234 Apr 27 15:10 timeclient.c
-rw-rw-r--  1 r6   r6    1234 Apr 27 15:10 timeclient.c~
-rw-rw-r--  1 r6   r6    1880 Apr 27 15:13 timeserver.c
-rw-rw-r--  1 r6   r6    1880 Apr 27 15:13 timeserver.c~
-rw-rw-r--  1 r6   r6     903 Apr  2 15:47 udpc.c
-rw-rw-r--  1 r6   r6     823 Apr  2 15:16 udpc.c~
-rw-rw-r--  1 r6   r6    1079 Apr  2 15:49 udpcs.c
-rw-rw-r--  1 r6   r6    1079 Apr  2 15:49 udpcs.c~
drwxr-xr-x  2 r6   r6    4096 Jan 29 15:19 Videos
-rw-------  1 r6   r6     285 Apr 27 14:35 .Xauthority
-rw-------  1 r6   r6     108 Apr 27 14:35 .xsession-errors
-rw-------  1 r6   r6     910 Apr 12 14:50 .xsession-errors.old
  108 Apr 27 14:35 .xsessio
1:LIST
2:LOAD
3:Exit : 2
Enter filename : shm.c 

1:LIST
2:LOAD
3:Exit : 3

*/
