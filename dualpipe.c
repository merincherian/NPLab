/* R6-39 MINI AISHWARYA
   EXPERIMENT 5
*/

#include<stdio.h>
#include<string.h>
#include<sys/ipc.h> // Header file for pipe system call

int main()
{
 	// DUAL PIPE. PARENT - CHILD AND CHILD-PARENT
	// FD1 FOR PARENT. FD2 FOR CHILD

	 int fd1[2],fd2[2],len,pid,len2;
	 char message[40]=" This is a test for parent. ";
	 char message2[40]=" This is a test for child. ";
	 char reply[40]=" ";
	
	 len=strlen(message);
	 len2=strlen(message2);

	 pipe(fd1);
	 pipe(fd2);

	 pid=fork();
 
	 if(pid<0)
	 {
		  printf("Error");
		  exit(0);
	 }
	 else if(pid>0)			// PARENT PROCESS
	 {
	  	close(fd1[0]);
	  	close(fd2[1]);
	  	
                write(fd1[1],message,len);
		printf("Message sent by parent( pid - %d ): %s",getpid(),message);
		printf("\n");
		read(fd2[0],reply,len);
		printf("Message received by parent( pid - %d ): %s",getpid(),reply);
		printf("\n");

	        close(fd1[1]);
		close(fd2[0]);
	 }
 	else				// CHILD PROCESS
 	{
  		close(fd1[1]);
  		close(fd2[0]);
  		
		write(fd2[1],message2,len);
	        printf("Message sent by child( pid - %d ): %s",getpid(),message2);
  		printf("\n");
    		read(fd1[0],reply,len);
  		printf("Message received by parent( pid - %d ): %s",getpid(),reply);
  		printf("\n");
  	
		close(fd1[0]);
  		close(fd2[1]);
 	}

 	return 0;
}
