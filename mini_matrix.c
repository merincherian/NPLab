/* R6-39 MINI AISHWARYA
   EXPERIMENT 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int A[10][10],B[10][10],C[10][10],D[10][10],i,j,k,s,m,n;
	int pid;
	
	printf(" Enter the number of rows: ");
	scanf("%d",&m);

	printf(" Enter the number of columns: ");
	scanf("%d",&n);

	printf( " Enter the elements of the first matrix: ");
	for( i = 0 ; i<m ; i++ )
	{
		for( j = 0 ; j<n ; j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
   
	
	printf(" Enter the elements of the second matrix: ");
	for( i = 0 ; i<m ; i++ )
	{
		for( j = 0 ; j<n ; j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
   
  	
	pid = fork();
	
	if ( pid > 0 )
	{
		printf(" \n Parent pid : %d ", getpid());		
		printf("\n Addition of matrices ");
		for( i = 0 ; i<m ; i++)
		{
			for( j=0; j<n;j++)
			{
				C[i][j]=A[i][j] + B[i][j];
			}	
		}	

		printf( " \n The resultant matrix : ");
		for( i = 0 ; i<m ; i++ )
		{
 			printf("\n");
			for ( j = 0 ; j < n ; j++)
			{
				printf("%d \t ",C[i][j]);
			}
		}
	}
	else if ( pid == 0 )
	{
				
		printf(" Child process : %d ",getpid());
		printf("\n Multiplication of matrices");
		
			for( i = 0 ; i<m ; i++ )
		{
 			printf("\n");
			for ( j = 0 ; j < n ; j++)
			{
				D[i][j]=1;
			}
		}
		
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				s=0;
				for (k=0;k<n;k++)
				{
					D[i][j]=D[i][j]+(A[i][k]*B[k][j]);
				}
			}
		}
		printf("\nThe resultant matrix is: ");
		for (i=0;i<m;i++)
		{
			printf("\n");
			for (j=0;j<n;j++)
			{
				printf("%d \t",D[i][j]);
			}
		}
	
	}
	else
	{
		printf("Error");
		exit(1);
	}
	
return;
}

