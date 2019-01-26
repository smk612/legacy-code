/*C Program to Create a Spiral Matrix*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j,r,c,ch=0,e=0,ur,uc,lr=0,lc=0;
	printf("\n\tEnter size ::");
	scanf("%d %d",&r,&c);
	ur=r-1;
	uc=c-1;
	
	/*Allocate memory space for the matrix*/
	int **mat=(int **)malloc(r*sizeof(int *));
	if(!mat)
	{
		printf("\n\tAllocation failed");
		return 2;
	}
	for(i=0;i<r;i++)
		{
			mat[i]=(int*)malloc(c*sizeof(int));
			if(!mat[i])
			{
				printf("\n\tAllocation failed");
				return 1;
			}
		}
	i=0;
	
	/*Loop to create the Matrix as Spiral*/
	while(e<r*c)
	{
	    if(ch%2==0)
	    {
	    
	    	/*Put the elements in the upper right boundary of the matrix */
	        for(j=lc;j<=uc;j++)
	        {
	            printf("\n\tEnter element at %d %d::\t",i,j);
	            scanf("%d",&mat[i][j]);e++;
	        }
	        lr++;j--;
	        for(i=lr;i<=ur;i++)
	        {
	             printf("\n\tEnter element at %d %d::\t",i,j);
	            scanf("%d",&mat[i][j]);e++;
	        }
	        uc--;i--;
	    }
	    else
	    {
	    	/*Put the elements in the lower left boundary of the matrix */
	        for(j=uc;j>=lc;j--)
	        {
	             printf("\n\tEnter element at %d %d::\t",i,j);
	            scanf("%d",&mat[i][j]);e++;
	        }
	        ur--;j++;
	        for(i=ur;i>=lr;i--)
	        {
	            printf("\n\tEnter element at %d %d::\t",i,j);
	            scanf("%d",&mat[i][j]);e++;
	        }
	        lc++;i++;
	    }
	    ch++;
	}
	
	/*Print the matrix in its final form*/
	printf("\n\tThe Matrix is ::\n");
	for(i=0;i<r;i++)
	{
	    for(j=0;j<c;j++)
	    {
	        printf("\t%d",mat[i][j]);
	    }
	    printf("\n");
	}
	return 0;		
}
