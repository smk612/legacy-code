/*C Program to Dynamically allocate a 2D Matrix and find its individual Row and Column Sum*/
#include <stdio.h>
#include <stdlib.h>
int main()
{	
	int i,j,r,c;
	
	/*Read the Size of the array*/
	printf("Enter size: ");
	scanf("%d %d",&r,&c);
	
	/*Dynamically(contiguous) allocate the 2D Matrix and Check if memory correctly allocated or not*/
	int **mat=(int **)malloc(r*sizeof(int*));
	if(!mat)
		{
			printf("Allocation failed\n");
			exit(1);
		}
	mat[0]=(int *)malloc(r*c*sizeof(int));
	if(!mat[0])
	{
		printf("Allocation failed\n");
		exit(2);
	}
	for(i=1;i<r;i++)
	{	
		mat[i]=mat[0]+(c*i);
		if(!mat[i])
		{
			printf("Allocation failed\n");
			exit(3);
		}
	}
				
	/*Read the elements of the Matrix*/
	printf("Enter elements\n");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%d",&mat[i][j]);
			}
		}
		
	/*Call function to find Individual row and column sum*/
	sum(mat,r,c);
	
	/*Free the allocated memory*/
	free(mat);
	return 0;
}
