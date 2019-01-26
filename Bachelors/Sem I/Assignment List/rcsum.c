/*C Program to Find and Display Individual Row and Column Sum*/
#include <stdio.h>
int sum(int **mat,int r,int c)
{
	int i,j,sr,sc[c];
	printf("The given Matrix along with Individual Row and Column Sum is:\n");
	
	/*Find Individual Row and Column Sum and Display*/
	for(i=0;i<r;i++)
	{	
		sr=sc[i]=0;
		for(j=0;j<c;j++)
		{
			printf("%d\t",*(mat[i]+j));
			sr=sr+*(mat[i]+j);
			sc[i]=sc[i]+*(mat[j]+i);
		}
		printf("|%d\n",sr);
	}
	for(i=0;i<c;i++)
	{
		printf("_\t");
	}
	printf(".\n");
	for(i=0;i<c;i++)
	{
		printf("%d\t",sc[i]);
	}	
	printf("\n");
	return 0;
}
