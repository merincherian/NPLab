/* R6-39 MINI AISHWARYA
   EXPERIMENT-7
*/

#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <string.h> 
  
// Structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[100]; 
} message1,message2,message3,message4; 
  
int main() 
{ 
    key_t key; 
    int msgid; 
    char msg3[20]=" ";
  
    // Generate unique key 
    key = 99; 
  
    // msgget() creates a message queue 
    // and returns identifier(msgid) 

    msgid = msgget(key, 0666 | IPC_CREAT); 
    message1.mesg_type = 1; 
  
    printf("\n Enter the first string:  "); 
    gets(message1.mesg_text); 
  
    // msgsnd() to send message 
    msgsnd(msgid, &message1, sizeof(message1), 0); 

    printf("\n Enter the second string:  "); 
    message2.mesg_type = 1; 
    gets(message2.mesg_text); 

    msgsnd(msgid, &message2, sizeof(message2), 0); 
  
    // Display the message 
    printf("Messages sent : %s %s \n", message1.mesg_text,message2.mesg_text); 

    msgrcv(msgid, &message3, sizeof(message3),1, 0);
  
    printf("Data received is : %s\n",message3.mesg_text); 
    
    // Delete the message queue 
    msgctl(msgid, IPC_RMID, NULL);
   
    return 0; 
} 
