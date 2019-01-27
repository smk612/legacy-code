#include <stdio.h>
#include <stdlib.h>
#define datatype int
void create_graph(datatype **graph,int n)
{
	int i,j,x;
	datatype w;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			graph[i][j]=9999;
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
			{	
				if(graph[x][i]==9999)
				{
					printf("\tEnter corresponding weight::");
					scanf("%d",&w);
					graph[i][x]=w;
				}
				else
					graph[i][x]=graph[x][i];
				printf("\tEnter next adjoining vertex::");
			}
		}
	}
}
void print_graph(datatype **graph,int n)
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
	datatype **graph= (datatype**)malloc(n*sizeof(datatype*));
	for(i=0;i<n;i++)
	{
		graph[i]=(datatype*)malloc(n*sizeof(datatype));
	}	
	create_graph(graph,n);
	print_graph(graph,n);
	return 0;
}
