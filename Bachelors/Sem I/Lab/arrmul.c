#include <stdio.h>
#include <stdlib.h>
void main()
{
	int i,j,s=0,k,m,n,x,y;
	printf("Enter size of A separated by space\n");
	scanf("%d %d",&m,&n);
	printf("Enter size of B separated by space\n");
	scanf("%d %d",&x,&y);
	if(n!=x)
	{
	printf("The arrays cannot be multiplied.\n");
	exit(0);
	}
	int a[m][n],b[x][y],c[m][y];
	printf("Enter A of size %d by %d\n",m,n);
	for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	{
	scanf("%d",&a[i][j]);
	}
	}
	printf("Enter B of size %d by %d\n",x,y);
	for(i=0;i<x;i++)
	{
	for(j=0;j<y;j++)
	{
	scanf("%d",&b[i][j]);
	}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<y;j++)
		{
		s=0;
			for(k=0;k<n;k++)
			{
			s=s+(a[i][k]*b[k][j]);
			}
		c[i][j]=s;
		}
	}
	printf("The Answer is\n");
	for(i=0;i<m;i++)
	{
	for(j=0;j<y;j++)
	{
	printf("%d\t",c[i][j]);
	}
	printf("\n");
	}
}
