//C Program to find smallest path between all pair of vertices using Floyd Warshall
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
void print_path(int **prev,int i,int j)
{
	if(prev[i][j]==-1)
		printf("-%d-%d",i,j);
	else
	{
		print_path(prev,i,prev[i][j]);
		print_path(prev,prev[i][j],j);
	}
}
void floyd_warshall(datatype **graph,int n)
{
	int i,j,k,s,dest;
	char ch='y';
	datatype **d= (datatype**)malloc(n*sizeof(datatype*));
	datatype **prev= (int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		d[i]=(datatype*)malloc(n*sizeof(datatype));
		prev[i]=(int*)malloc(n*sizeof(int));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			d[i][j]=graph[i][j];
			prev[i][j]=-1;
		}
	}
	for(k=1;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((d[i][k]+d[k][j])<d[i][j])
				{
					d[i][j]=d[i][k]+d[k][j];
					prev[i][j]=k;
				}
			}
		}
	}
	printf("\n\tThe distances are::");
	for(i=-1;i<n;i++)
	{
		printf("\n");
		for(j=-1;j<n;j++)
		{
			if((i==-1)&&(j==-1))
				printf("From|To");
			else if(i==-1)
				printf("%d",j);
			else if(j==-1)
				printf("%d",i);
			else
				printf("%d",d[i][j]);
			printf("\t");
		}
	}
	printf("\n");
	do
	{
		printf("\n\tDo you want to display a path(y/n)::");
		getchar();
		scanf("%c",&ch);
		if(ch=='n'||ch=='N')
			break;
		printf("\tEnter source::");
		scanf("%d",&s);
		printf("\tEnter destination:");
		scanf("%d",&dest);
		if(d[s][dest]!=9999)
		{
			printf("\tThe path from %d to %d is::",s,dest);
			print_path(prev,s,dest);
		}
		else
			printf("\n\tNo such path exists.");
	}
	while(ch=='y'||ch=='Y');
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
	floyd_warshall(graph,n);
	return 0;
}
