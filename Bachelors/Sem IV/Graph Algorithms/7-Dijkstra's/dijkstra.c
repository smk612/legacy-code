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
void print_path(int *prev,int n,int dest)
{
	int u=dest,i=n-1;
	int *s = (int*)malloc(n*sizeof(int));
	while(prev[u]!=-1)
	{
		s[i--]=u;
		u=prev[u];
	}
	s[i]=u;
	for(;i<n;i++)
	{
		printf("%d-",s[i]);
	}
}
void dijkstra(datatype **graph,int n)
{
	int i,s,q=n,min,dest,u;
	datatype dist1;
	char ch='y';
	int *mark = (int*)malloc(n*sizeof(int));
	datatype *dist = (datatype*)malloc(n*sizeof(datatype));
	int *prev = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		mark[i]=1;
		dist[i]=9999;
		prev[i]=-1;
	}
	printf("\n\tEnter the source vertex::");
	scanf("%d",&s);
	dist[s]=0;
	while(q!=0)
	{
		for(i=0,min=9999;i<n;i++)
		{
			if((mark[i]==1)&&(dist[i]<min))
			{
				min=dist[i];
				u=i;
			}
		}
		printf("%d",u);
		mark[u]=0;
		q--;
		for(i=0;i<n;i++)
		{
			if((graph[u][i]!=9999)&&(mark[i]==1))
			{
				dist1=dist[u]+graph[u][i];
				if(dist1<dist[i])
				{
					dist[i]=dist1;
					prev[i]=u;
				}
			}
		}
	}
	printf("\n\tThe distances from %d are:",s);
	for(i=0;i<n;i++)
		printf("\n\tto %d = %d",i,dist[i]);
	do
	{
		printf("\n\tDo you want to display a path(y/n)::");
		getchar();
		scanf("%c",&ch);
		if(ch=='n'||ch=='N')
			break;
		printf("\tEnter destination::");
		scanf("%d",&dest);
		if(dist[dest]!=9999)
		{
			printf("\tThe path from %d to %d is::",s,dest);
			print_path(prev,n,dest);
		}
		else
			printf("\n\tNo Path.");
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
	dijkstra(graph,n);
	return 0;
}
