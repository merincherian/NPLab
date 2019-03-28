/* R6-39 MINI AISHWARYA
   EXPERIMENT 3
*/

#include<stdio.h>

main()
{
	// PARENT PROCESS PERFORMS MATRIX MULTIPLICATION.
	// CHILD PROCESS PERFORMS MATRIX ADDITION.

	int pid,a[100][100],b[100][100],c[100][100],i,j,k,s,m,n;

	printf("Enter the number of rows: ");
	scanf("%d",&m);

	printf("Enter the number of columns: ");
	scanf("%d",&n);

	printf("\nEnter the elements of first matrix: \n");
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	printf("\nEnter the elements of second matrix: \n");
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}

	pid=fork();

	if (pid==0)
	{
		printf("\nThis is the Child Process (Process ID= %d)",getpid());
		if (m!=n)
		{
			printf("Multiplication is not possible");
		}
		else
		{
			for (i=0;i<m;i++)
			{
				for (j=0;j<n;j++)
				{
					s=0;
					for (k=0;k<n;k++)
					{
						c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
					}
				}
			}
			printf("\nThe resultant matrix is: ");
			for (i=0;i<m;i++)
			{
				printf("\n");
				for (j=0;j<n;j++)
				{
					printf("%d\t",c[i][j]);
				}
			}
		}
	}
	else if (pid<0)
	{
		printf("ERROR: No Child process is created.\n");
	}
	else
	{
		printf("\nThis is the Parent Process (Process ID= %d)",getpid());

		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				c[i][j]=a[i][j]+b[i][j];
			}
		}

		printf("\nThe resultant matrix is: ");
		for (i=0;i<m;i++)
		{
			printf("\n");
			for (j=0;j<n;j++)
			{
				printf("%d\t",c[i][j]);
			}
		}
	}
	
		printf("\n");
}
