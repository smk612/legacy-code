#include <stdio.h>
#include <stdlib.h>
display(int **mat1,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		printf("%d\t",mat[i]+j);
		printf("\n");
	}
}
void main()
{
	int r,c,i;
	printf("Enter size\n");
	scanf("%d",&r,&c);
	int **mat1=(int **)malloc(r*sizeof(int));
	
	for(i=0;i<r;i++)
	{
		mat1[i]=(int*)malloc(c*sizeof(int));
	}
}
