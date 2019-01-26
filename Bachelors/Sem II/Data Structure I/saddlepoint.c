/* C Program to find all possible Saddlepoints in a Matrix*/
#include <stdio.h>
#include <stdlib.h>
int saddlepoint(int **a,int m,int n);
int display(int **mat,int r,int c);
int main()
{
	int r,c,i,j;
	printf("\n\tEnter size ::");
	scanf("%d %d",&r,&c);
	
	/*Allocate space for the matrix*/
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
	
	/*Read user input*/
	printf("\n\tEnter elements::");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	printf("\n\tThe Matrix is::\n");
	display(mat,r,c);
	saddlepoint(mat,r,c);
	for(i=0;i<r;i++)
	{
		free(mat[i]);
	}
	free(mat);
	return 0;
}

/*Function to find saddlepoints and print them*/
int saddlepoint(int **a,int m,int n)
{
	int i,j,p,q,k,c=0,max,min;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			min=a[i][j];p=i;
			max=a[i][j];q=j;
			
			/*Loop to find min of row*/
			for(k=0;k<n;k++)
			{
				if(min>a[i][k])
				{
					min=a[i][k];
					q=k;
				}
			}
			
			/*Loop to find max of column*/
			for(k=0;k<m;k++)
			{
				if(max<a[k][j])
				{
					max=a[k][j];
					p=k;
				}
			}
			if((p==i)&&(q==j))
			{
				c++;
				printf("\n\tSaddle Point %d at ::%d,%d=%d\n",c,i,j,a[i][j]);
			}
		}
	}
	if(c==0)
	{
		printf("\n\tNo saddlepoint found.\n");
	}
	return 0;
}

/*Function to Display Matrix*/
int display(int **mat,int r,int c)
{
	int i,j;
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
