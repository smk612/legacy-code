#include <stdio.h>
#include <stdlib.h>
display(int **mat,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		printf("%p\t%d\t||",&mat[i][j],*(mat[i]+j));
		}
		printf("\n");
	}
}
void main()
{
	int r,c,i,j,ch,x=0;
	printf("Enter size\n");
	scanf("%d %d",&r,&c);
	int **mat=(int **)malloc(r*sizeof(int *));//int * is used
	do
	{
	printf("Enter 1 for non-continuous allocation\nEnter 2 for continuous allocation\nEnter 3 to initialise\nEnter 4 to display\nEnter 5 to free\nEnter 6 to exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:	for(i=0;i<r;i++)
		{
			mat[i]=(int*)malloc(c*sizeof(int));
			//if()
		}
		x=1;
		/*for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			*(mat[i]+j)=0;
		}*/
		break;
	case 2:	mat[0]=(int *)malloc(r*c*sizeof(int));
		for(i=1;i<r;i++)
		mat[i]=mat[0]+(c*i);
		x=2;
		break;
	case 3:	printf("Enter elements\n");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			scanf("%d",&mat[i][j]);
		}
		x=3;
		break;
	case 4: if(x==0)
		printf("No allocation is done yet\n");
		//else if(x==2||x==1)
		//printf("Allocation done but not initialised\n");
		else
		display(mat,r,c);
		break; 
	case 5: printf("%d\n",x);
		if(x==0)
		printf("No allocation is done yet\n");
		if(x==1)
		{printf("%p\n",&mat[0]);
		for(i=0;i<r;i++)
		{
			printf("%p\n",mat[i]);
			free(mat[i]);
		}
		printf("%p\n",mat);
		}
		if(x==2)
		{printf("%p\n",&mat);
		free(mat);}
		x=0;
		break;
	}
	}
	while(ch!=6);
}
	
