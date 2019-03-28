/* R6-39 MINI AISHWARYA
   EXPERIMENT-6
*/

#include<stdio.h>
#include<sys/shm.h>

int main()
{
	// A shared memory is created between the client and server process. 
	// shmid - sharedmemory id which is a unique id

	int shmid,addr;
	char str1[10]="";
        
	// key is the unique key for a shared memory.
	// key_t is the data type for key
	// both client and server process use this key for sharing.
	key_t key;	
 	key=100;       
	
	// shmget() is used to create the shared memory.
	// Parameters - (key,sizeof(string),FLAG|0666)
	// IPC_CREATE is a flag that is used to create the shared memory( if it does not exist).
	// 0666 is used to provide access(permissions) for read, write, execute.
	shmid=shmget(key,100,IPC_CREAT|0666);	

	// shmat() is used to attach the shared memory to the process.
	// it returns an address of the memory location.						
	addr=shmat(shmid,NULL,0);

	printf("\n Client side - ");
	printf(" \n \t Enter the expression: ");
        scanf("%s",str1);

	// sprintf() is used to insert strings into the memory.
	sprintf(addr,str1);

	// shmdt() is used to dettach the memory.
	shmdt(addr);
       
	return 0;




}
