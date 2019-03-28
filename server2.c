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
} message1,message2,message3; 
  
int main() 
{ 
    key_t key; 
    int msgid; 
    char msg3[50]=" ";
      
    key = 99; 
  
    // msgget() creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
  
    // msgrcv to receive message 
    msgrcv(msgid, &message1, sizeof(message1),1, 0);

    msgrcv(msgid, &message2, sizeof(message2),1, 0);  
  
    // display the message 
    printf("Messages received: %s %s",message1.mesg_text,message2.mesg_text);
    
    strcat(msg3,message1.mesg_text);
    strcat(msg3,message2.mesg_text);
    
    //message3.mesg_type=1;
    
    strcpy(message3.mesg_text,msg3);

    message3.mesg_type=1;
    
    msgsnd(msgid, &message3, sizeof(message3), 0); 
  
    return 0; 
} 
