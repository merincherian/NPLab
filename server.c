/* R6-39 MINI AISHWARYA
   EXPERIMENT-6
*/

#include<stdio.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
	int shmid,addr,i,j,result;
	int num[5];
        char str2[10]=" ";
        
	key_t key,new_key;
 	key=100;
	result=0;

	shmid=shmget(key,100,IPC_CREAT|0666);
	addr=shmat(shmid,NULL,0);

	// sscanf() is used to receive the string from the shared memory.	
	sscanf(addr,"%s",str2);

	shmdt(addr);

	// Evaluating the expression
	for(i=0;i<strlen(str2);i++)
	{
		if(isdigit(str2[i]))
		{
			result=result + str2[i] - 48;
		}

	}

        printf("\n Result: %d",result);

	return 0;

}
