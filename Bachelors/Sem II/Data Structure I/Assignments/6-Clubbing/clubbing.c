/*C Program to Club an Upper Triangular and a Lower Triangular Matrix together*/
#include <stdio.h>
int main()
{
	int i,j,r=3,c=3;
	int a[r][c],b[r][c],d[r][c+1];
	
	/*Read user input*/
	printf("\tEnter elements of the lower Triangular matrix::");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\tEnter elements of the Upper Triangular matrix::");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	
	/*Club the two matrices together*/
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i>j)
			{
				d[i][j]=a[i][j];
			}
			else if(i<j)
			{
				d[i][j+1]=b[i][j];
			}
			else
			{
				d[i][j]=a[i][j];
				d[i][j+1]=b[i][j];
			}
		}
	}
	
	/*Print the input*/
	printf("\n\tUpper Triangular Matrix\t\tLower Triangular Matrix\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\t");
		for(j=0;j<c;j++)
		{
			printf("\t%d",b[i][j]);
		}
		printf("\n");
	}
	
	/*Print the result*/
	printf("\tThe Clubbed Matrix is:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c+1;j++)
		{
			printf("\t%d",d[i][j]);
		}
		printf("\n");
	}
	return 0;
}
