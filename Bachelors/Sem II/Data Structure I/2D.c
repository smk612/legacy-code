#include <stdio.h>
#include <stdlib.h>
display(int **mat,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}
int saddlepoint(int **a,int m,int n)
{
	int i,j,p,q,k,c=0,max,min;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			max=a[i][j];p=i;
			min=a[i][j];q=j;
			for(k=0;k<m;k++)
			{
				if(max<a[i][k])
				{
					max=a[i][k];
					q=k;
				}
			}
			for(k=0;k<n;k++)
			{
				if(min>a[k][j])
				{
					min=a[k][j];
					p=k;
				}
			}
			if((p==i)&&(q==j))
			{
				c++;
				printf("Saddle Point %d at ::%d%d=%d\n",c,i,j,a[i][j]);
			}
		}
	}
	if(c==0)
	{
		printf("No saddlepoint found.\n");
	}
	return 0;
}
int main()
{
	int i,j,r,c,ch;
	printf("Enter size ::");
	scanf("%d %d",&r,&c);
	int **mat=(int **)malloc(r*sizeof(int *));
	if(!mat)
	{
		printf("Allocation failed");
		return 2;
	}
	for(i=0;i<r;i++)
		{
			mat[i]=(int*)malloc(c*sizeof(int));
			if(!mat[i])
			{
				printf("Allocation failed");
				return 1;
			}
		}
	printf("Enter elements\n");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			scanf("%d",&mat[i][j]);
		}
	
	do
	{
	printf("Enter 1 to find Saddle Points,\n2 to Convert it to Spiral \nor 3 to Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:saddlepoint(mat,r,c);
			break;
		//case 2:spiral(mat,r,c);
			break;
		default:printf("EndOfProgram\n");
			for(i=0;i<r;i++)
			{
				free(mat[i]);
			}
			ch=0;
	}
	}
	while(ch!=0);
	return 0;
}
