//C Code to Traverse a given graph using BFS using Adjacency List
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int q[MAX];
int front=0,rear=0;
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node *NODEPTR;
NODEPTR allocate_node(int item)//Allocates memory space for a new node
{
	NODEPTR temp = (NODEPTR)malloc(sizeof(struct Node));
	temp->data=item;
	temp->next=NULL;
	return temp;
}
void create_graph(struct Node **graph,int n)
{
	int i=0,j;
	for(i=0;i<n;i++)
	{
		NODEPTR start=NULL;
		int item;
		printf("\n\tEnter the adjoining vertices of %d. Enter -99 to stop.",i);
		for(j=0;j<n;j++)
		{
			scanf("%d",&item);
			if(item==-99)
				break;
			else
			{
				NODEPTR temp=allocate_node(item);
				if(start==NULL)
				{
					start=temp;
				}
				else
				{	
					NODEPTR p=start,q;
					while((p!=NULL)&&((temp->data)>(p->data)))
					{
						q=p;
						p=p->next;
					}
					temp->next=p;
					if(p==start)
						start=temp;
					else
						q->next=temp;
				}
			}
		}
		(graph[i])->next=start;	
	}
}
void print_graph(struct Node **graph,int n)
{
	int i;
	printf("\n\tThe Adjacency List of the Graph is::");
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("Vertex%d",(graph[i])->data);
		if((graph[i])->next==NULL)
   	 	{
        		printf("\n\tThe vertice has no adjacent vertices.");
   	 	}
   	 	else
   	 	{
   	 		NODEPTR p=(graph[i])->next;
   	 		while(p!=NULL)
			{
				printf("\t->%d",p->data);
				p=p->next;
			}
   	 	}	
	}
	printf("\n");
}
int is_full()
{
	if((rear+1)%MAX==front)
		return 1;
	else
		return 0;
}
int is_empty()
{
	if(front==rear)
		return 1;
	else
		return 0;
}
void enqueue(int n)
{
	if(is_full()==0)
	{
		q[rear]=n;
		rear=(rear+1)%MAX;
	}
	else
		printf("\tThe Queue is Full.");
}
int dequeue()
{
	if(is_empty()==0)
	{
		int x=q[front];
		front=(front+1)%MAX;
		return x;
	}
	else
		printf("\tThe Queue is Empty.");
	return -9999;	
}
int bfs(struct Node **graph,int n,int *mark,int v,int x)
{
	int r;
	front=rear=0;
	enqueue(v);
	mark[v]=1;
	enqueue(-99);
	while(is_empty()==0)
	{
		r=dequeue();
		if(r!=-9999)
		{
			if(r==-99)
				printf("\n");
			else
			{
				printf("\t%d",r);
				NODEPTR p=(graph[r])->next;
				while(p!=NULL)
				{
					if(mark[p->data]==0)
					{
						mark[p->data]=x;
						enqueue(p->data);
					}
					p=p->next;
				}
				enqueue(-99);
			}
		}
	}
	return 0;
}
int main()
{
	int n,i,v,x=1;
	printf("\n\tEnter the number of vertices::");
	scanf("%d",&n);
	int *mark=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		mark[i]=0;
	struct Node **graph= (struct Node**)malloc(n*sizeof(struct Node*));
	for(i=0;i<n;i++)
	{
		graph[i]=(struct Node*)malloc(sizeof(struct Node));
		graph[i]->data=i;
		graph[i]->next=NULL;
	}	
	create_graph(graph,n);
	print_graph(graph,n);
	for(i=0;i<n;i++)
		mark[i]=0;
	printf("\tThe BFS traversal is::\n");
	bfs(graph,n,mark,0,x);
	x=x+1;
	for(i=0;i<n;i++)
	{
		if(mark[i]==0)
		{
			bfs(graph,n,mark,i,x);
			x=x+1;
		}
	}
	printf("\n\tNo of components::%d\n",x-1);
	return 0;
}
