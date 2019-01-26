#include <stdio.h>
int main()
{
	int i,j,r=3,c=3;
	//printf("\tEnter size ::");
	//scanf("%d %d",&r,&c);
	int a[r][c],b[r][c],d[r][c+1];
	printf("\tEnter elements of 1st matrix::");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\tEnter elements of 2nd matrix::");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
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
	printf("\tThe Clubbed Matrix is:\n\t");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c+1;j++)
		{
			printf("%d\t",d[i][j]);
		}
		printf("\n\t");
	}
}
