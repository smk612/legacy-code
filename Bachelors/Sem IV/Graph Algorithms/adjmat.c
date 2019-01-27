#include <stdio.h>
#include <stdlib.h>
void create_graph(int **graph,int n)
{
	int i,j,x;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			graph[i][j]=0;
		}
	}
	printf("\tIdentify the adjoining vertices:");
	for(i=0;i<n;i++)
	{
		printf("\n\tEnter the adjoining vertices of %d.Enter -99 to stop::",i);
		for(j=0;j<n;j++)
		{
			scanf("%d",&x);
			if(x==-99)
				break;
			else
				graph[i][x]=1;
		}
	}
}
void print_graph(int **graph,int n)
{
	int i,j;
	printf("\n\tThe Adjacency Matrix of the Graph is::");
	for(i=-1;i<n;i++)
	{
		printf("\n");
		for(j=-1;j<n;j++)
		{
			if(i==-1)
				printf("%d",j);
			else if(j==-1)
				printf("%d",i);
			else
				printf("%d",graph[i][j]);
			printf("\t");
		}
	}
	printf("\n");
}
int main()
{
	int n,i;
	printf("\n\tEnter the number of vertices::");
	scanf("%d",&n);
	int **graph= (int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		graph[i]=(int*)malloc(n*sizeof(int));
	}	
	create_graph(graph,n);
	print_graph(graph,n);
	return 0;
}
