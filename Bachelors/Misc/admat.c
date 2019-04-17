/*C Program to create Graph using Adjacency Matrix
Assumptions: All vertex names are in integer format
*/
#include <stdio.h>
#include <stdlib.h>
int *ver_name;
int ver_exists(int x,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(ver_name[i]==x)
			return i;
	}
	return -1;
}

void create_graph(int **graph,int n)
{
	int i,j,x,y;
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
		printf("\n\tEnter the adjoining vertices of %d.Enter -99 to stop::",ver_name[i]);
		for(j=0;j<n;j++)
		{
			scanf("%d",&x);
			if(x==-99)
				break;
			else
			{
				y=ver_exists(x,n);
				if(y!=1)
					graph[i][y]=1;
				else
				{
					printf("\tVertex %d doesn't exist. Please Enter again.",x);
					i--;
					break;
				}
			}
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
	int n,i,x;
	printf("\n\tEnter the number of vertices::");
	scanf("%d",&n);
	ver_name=(int*)malloc(n*sizeof(int));
	printf("\tEnter the name of the vertices::");
	/*For character datatype
	for(i=0;i<n;i++)
	{
		scanf(" %c",&x);//space before the %c ignores spaces in the input
		ver_name[i]=x;
	}
	getchar();
	*/
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		ver_name[i]=x;
	}
	int **graph= (int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		graph[i]=(int*)malloc(n*sizeof(int));
	}	
	create_graph(graph,n);
	print_graph(graph,n);
	return 0;
}
