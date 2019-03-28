/* R6-39 MINI AISHWARYA
   EXPERIMENT 5
*/

#include<stdio.h>
#include<string.h>
#include<sys/ipc.h> // header file for pipe system call

int main()
{
 int pid,pid2,fd[2];
 char message1[40]=" ";
 char message2[40]=" ";
 char parentmessage[50]=" ";
 
 pipe(fd);
 pid=fork();
 
 if(pid<0)
 {
   printf("error");
   exit(0);
 }
 else if(pid>0)
 {
  close(fd[1]);
  read(fd[0],message2,strlen(message2));
  strcat(parentmessage,message2);
  close(fd[0]);
 }
 else
 {
  close(fd[0]);
  printf(" Enter the message of first child: ");
  gets(message1);
  write(fd[1],message1,strlen(message1));
  close(fd[1]);

  pid2=fork();
  if(pid2<0)
  {
   printf("error");
   exit(0);
  }
  else if(pid2==0)
  {
   close(fd[0]);
   printf(" Enter the message of second child: ");
   /*gets(message2);
   sleep(100);
   write(fd[1],message2,strlen(message2));
   close(fd[1]);*/
  }
  else
  {
  gets(message2);
   sleep(100);
   write(fd[1],message2,strlen(message2));
  close(fd[1]);
  read(fd[0],message1,strlen(message1));
  strcat(parentmessage,message1);
  printf(" Parent message is %s",parentmessage);
  close(fd[0]);
  }

 }
 return 0;
}
