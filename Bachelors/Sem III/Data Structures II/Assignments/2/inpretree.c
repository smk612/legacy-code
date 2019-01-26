//C Program to Create a Binary Tree from Infix and Prefix Sequences
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
int pi=0;

/*The recursive function that forms a tree from the two sequences*/
int convert(int *pre,int *in,struct node**root,int li,int ri)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	if(li==ri)
	{
		temp->data=pre[pi];
		pi=pi+1;
		temp->left=NULL;
		temp->right=NULL;
		*root=temp;
	}
	else
	{
		int data,i;
		data=pre[pi];
		for(i=li;i<=ri;i++)
		{
			if(in[i]==data)
				break;			
		}
		temp->data=pre[pi];;
		temp->left=NULL;
		temp->right=NULL;
		*root=temp;
		pi++;
		if(li<=i-1)
			convert(pre,in,&(*root)->left,li,i-1);
		if(ri>=i+1)
			convert(pre,in,&(*root)->right,i+1,ri);
	}
	return 1;
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
int main()
{
	int n,i=0;
	printf("\n\tEnter number of nodes:");
	scanf("%d",&n);
	int *in=(int*)malloc(n*sizeof(int));
	int *pre=(int*)malloc(n*sizeof(int));
	printf("\n\tEnter Inorder Sequence::\n\t");
	while(i<n)
	{
		scanf("%d",&in[i++]);
		printf("\t");
	}
	i=0;
	printf("\n\tEnter Preorder Sequence::\n\t");
	while(i<n)
	{
		scanf("%d",&pre[i++]);
		printf("\t");
	}
	struct node* root=NULL;
	convert(pre,in,&root,0,n-1);
	printf("\n\tThe Tree is::\n");
	display(&root,0);
	return 0;
}
