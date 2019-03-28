/* R6-39 MINI AISHWARYA
   EXPERIMENT 5
*/

#include<stdio.h>
#include<string.h>
#include<sys/ipc.h> // Header file for pipe system call

int main()
{
 	// WE USE A SINGLE PIPE. PIPE IS CREATED USING PIPE(). 
 	// INT FD[2] - FD[0] IS FOR READEND, FD[1] IS WRITEEND
 	// A MESSAGE IS SENT BY PARENT VIA FD[1] AND THE MESSAGE IS RECEIVED BY CHILD VIA FD[0]
 	// -- IMPORTANT - CLOSE ALL THE READ AND WRITE ENDS!
 
	 int fd[2],len,pid;
	 char message[16]="This is a test.";
	 char reply[16]=" ";
	 len=strlen(message);

	 pipe(fd);
	 pid=fork();

	 if(pid<0)
	 {
	  	printf("Error");
	  	exit(0);
	 }
	 else if(pid>0)  			//PARENT PROCESS
	 {
	  	close(fd[0]);			
	  	write(fd[1],message,len);
	  	printf("Message sent by parent( pid - %d ): %s",getpid(),message);
	  	close(fd[1]);
	 }
	 else					//CHILD PROCESS
	 {
	  	close(fd[1]);
	  	read(fd[0],reply,len);
	  	printf("Message received by child( pid - %d ): %s",getpid(),reply);
	  	close(fd[0]);
	 }
	 return 0;
}
