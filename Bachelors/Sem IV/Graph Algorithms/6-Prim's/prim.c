//C Program to find the Minimum Spanning Tree using Prim's Algorithm and Adjacency Matrix
#include <stdio.h>
#include <stdlib.h>
#define datatype int
int create_graph(datatype **graph,int n)
{
	int i,j,x,c=0;
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
					c++;
				}
				else
					graph[i][x]=graph[x][i];
				printf("\tEnter next adjoining vertex::");
			}
		}
	}
	return c;
}
void print_graph(datatype **graph,int n,datatype **edge)
{
	int i,j,k=0;
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
			{
				printf("%d",graph[i][j]);
				if(i<j && graph[i][j]!=9999)
				{
					//storing the start and end vertices along with its weight
					edge[k][0]=graph[i][j];
					edge[k][1]=i;
					edge[k][2]=j;
					k++;
				}
			}
			printf("\t");
		}
	}
	printf("\n");
}
int modbubblesort(datatype **a,int m)
{
	int i,j,flag;
	datatype tmp;
	for(i=0;i<m;i++)
	{
		flag=0;
		for(j=0;j<m-i-1;j++)
		{
			if(a[j][0]>a[j+1][0])//checking on basis of weight
			{
				flag=1;
				//Swapping the array elements
				tmp=a[j][0];
				a[j][0]=a[j+1][0];
				a[j+1][0]=tmp;
				tmp=a[j][1];
				a[j][1]=a[j+1][1];
				a[j+1][1]=tmp;
				tmp=a[j][2];
				a[j][2]=a[j+1][2];
				a[j+1][2]=tmp;
			}
		}
		if(flag==0)//Indicates that all the elements are in their correct position and that no swapping has been done
			return 1;
	}
	return 0;
}
void prim(datatype **edge,int m,int n)
{
	int i,k,r,s,tot=0;
	int *mark = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		mark[i]=0;
	}
	mark[0]=1;k=-1;
	printf("\tThe Minimum Spanning Tree is::\n\tWeight\tStart\tEnd\n");
	for(i=0;i<n-1;)
	{
		k++;
		r=edge[k][1];
		s=edge[k][2];
		//printf("[%d,%d]{%d,%d}",r,s,mark[r],mark[s]);
		if(mark[r]!=mark[s])
		{
			tot=tot+edge[k][0];
			printf("\t%d\t%d\t%d\n",edge[k][0],edge[k][1],edge[k][2]);
			if(mark[r]==0)
				mark[r]=1;
			else
				mark[s]=1;
			i++;k=-1;
		}
	}
	printf("\tThe Total Weight is::%d\n",tot);
}
int main()
{
	int n,i,m;
	printf("\n\tEnter the number of vertices::");
	scanf("%d",&n);
	datatype **graph= (datatype**)malloc(n*sizeof(datatype*));
	for(i=0;i<n;i++)
	{
		graph[i]=(datatype*)malloc(n*sizeof(datatype));
	}	
	m=create_graph(graph,n);
	datatype **edge = (datatype**)malloc(m*sizeof(datatype*));
	for(i=0;i<m;i++)
	{
		edge[i]=(datatype*)malloc(3*sizeof(datatype));
	}
	print_graph(graph,n,edge);
	modbubblesort(edge,m);
	printf("The sorted edgeset is::\n\tWeight\tStart\tEnd\n");
	for(i=0;i<m;i++)
	{
		printf("\t%d\t%d\t%d\n",edge[i][0],edge[i][1],edge[i][2]);
	}
	prim(edge,m,n);
	return 0;
}
