#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct qnode
{
	struct node *data;
	struct qnode *next;
};
int insert(struct node **root,int item);
int display(struct node **root,int level);
struct node* dfs(struct node *root,int n);
int notempty(struct qnode *front);
int queuein(struct qnode **rear,struct node *inp);
int queuedel(struct qnode **front);
struct node* bfs(struct node *root,int n);
int main()
{
	int ch=1,n;
	struct node* root=NULL;
	while (ch!=0)
	{
		printf("\n\tMENU::\n\t1.Insert\n\t2.Delete\n\t3.Display as Tree\n\t0.Exit\n\tEnter Choice::");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:	printf("\n\tEnter number::");
			scanf("%d",&n);
			insert(&root,n);
			break;
		case 2: printf("\n\tEnter number::");
			scanf("%d",&n);
			//delete(&root,n);
			break;
		case 3:	printf("\n");
			display(&root,0);
			break;
		case 0: return 0;
			break;
		default:printf("\n\tInvalid Choice");
		}
	}
	return 0;
}
int insert(struct node **root,int item)
{
	if(*root==NULL)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->data=item;
		temp->left=NULL;
		temp->right=NULL;
		*root=temp;
		printf("\n\tRoot Set\n");
	}
	else
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->data=item;
		temp->left=NULL;
		temp->right=NULL;
		int n,ch;
		struct node *par=NULL;
		printf("\n\tDeclare the parent of the node::");
		scanf("%d",&n);
		printf("\n\tSpecify how to you want to search for the parent:\n\t1.BFS\tor\t2.DFS\n\tEnter Choice::");
		scanf("%d",&ch);
		if(ch==1)
			par=bfs(*root,n);
		else if(ch==2)
			par=dfs(*root,n);
		else
		{
			printf("\n\tInvalid choice.Exiting Insertion.");
			return 1;
		}
		if(par==NULL)
		{
			printf("\n\tItem not found in tree.");
			return 2;
		}	
		printf("\n\tEnter 1 if left child, 2 if right child:");
		scanf("%d",&ch);
		if(ch==1)
		{
			if(par->left==NULL)
				par->left=temp;
			else
				printf("\n\tChild already present.");
		}
		else if(ch==2)
		{
			if(par->right==NULL)
				par->right=temp;
			else
				printf("\n\tChild already present.");
		}
		else
		{
			printf("\n\tInvalid choice.Exiting Insertion.");
			return 3;
		}
	}
	return 0;
}
int display(struct node **root,int level)
{
	int i=0;
	if(*root==NULL)
		return 0;
	display(&(*root)->right,level+1);
	for(i=0;i<=level;i++)
		printf("\t");
	printf("%d\n",(*root)->data);
	display(&(*root)->left,level+1);
	return 1;
}
struct node* dfs(struct node *root,int n)
{
	if(root->data==n)
		return root;
	else
	{
		if(root->left!=NULL)
			return dfs(root->left,n);
		if(root->right!=NULL)
			return dfs(root->right,n);
	}
}
int notempty(struct qnode *front)
{
	if(front==NULL)
	{
		return 0;
	}
	else
		return 1;
}
int queuein(struct qnode **rear,struct node *inp)
{
	if(inp!=NULL)
	{
		struct qnode *temp=(struct qnode *)malloc(sizeof(struct qnode));
		temp->data=inp;
		temp->next=NULL;
		(*rear)->next=temp;
		*rear=temp;
	}
	return 0;
}
int queuedel(struct qnode **front)
{
	if(notempty(*front))
	{
		struct qnode *p=*front;
		(*front)=(*front)->next;
		free(p);
		p=NULL;
	}
	return 0;
}
struct node* bfs(struct node *root,int n)
{
	struct qnode *front=(struct qnode *)malloc(sizeof(struct qnode));
	front->data=root;
	front->next=NULL;
	struct qnode *rear=front;
	while(notempty(front))
	{
		queuein(&rear,(front->data)->left);
		queuein(&rear,(front->data)->right);
		if((front->data)->data==n)
			return (front->data);
		queuedel(&front);
	}
	return NULL;
}
