/* R6-39 MINI AISHWARYA
   EXPERIMENT 3
*/
 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int main()
{
	// ONE PARENT AND THREE CHILD PROCESS. 
        // FORK() SYSTEM CALL IS USED.
	
	pid_t pid1, pid2, pid3;
	
	printf(" Parent pid: %d " , getppid());
	printf("\n");

	pid1 = fork();

	if ( pid1 == 0 ) 
        {
		printf(" First child: ");
		printf("%d",getpid());
		printf("\n");
        }
	else if ( pid1 > 0 )
	{
		pid2 = fork();

		if ( pid2 == 0 )
		{
			printf(" Second child: ");
		        printf("%d",getpid());
		        printf("\n");
		}
		else if ( pid2 > 0 )
		{
			printf(" Parent pid: %d " , getppid());			

			pid3 = fork() ;

			if ( pid3 == 0 )
			{
				printf(" Third child: ");
				printf("%d",getpid());
				printf("\n");
 			}
			else if ( pid3 < 0 )
			{
				printf("Error1");
				exit(1);
			}
		}
		else
		{
			printf("Error2");
			exit(1);
		}
        }
	else
	{
		printf("Error3");
		exit(1);
	}

        return;
}

