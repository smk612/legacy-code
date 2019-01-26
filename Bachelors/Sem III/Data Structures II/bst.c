#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node* insert(struct node **root,int item)
{
	if(*root==NULL)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->data=item;
		temp->left=NULL;
		temp->right=NULL;
		*root=temp;
		printf("\n\tItem Inserted\n");
	}
	else
	{
		if((*root)->data>item)
		{
			printf("\n\tEntering the left of %d",(*root)->data);
			insert(&(*root)->left,item);
		}
		else if((*root)->data<item)
		{
			printf("\n\tEntering the right of %d",(*root)->data);
			insert(&(*root)->right,item);
		}
		else
		{
			printf("\n\tItem already present in tree.\n");
			return NULL;
		}
	}
	return(*root);
}
int freenode(struct node *p)
{
    free(p);
    p=NULL;
    return 0;
}
void del(struct node **root)
{
	struct node *temp=NULL,*temp1=*root;
	if(((*root)->left==NULL)&&((*root)->right==NULL))
	{
		*root=NULL;
	}
	else if(((*root)->left==NULL)||((*root)->right==NULL))
	{
		temp=((*root)->left==NULL)?(*root)->right:(*root)->left;
		*root=temp;
	}
	else
	{
		temp=(*root)->left;
		if(temp->right==NULL)
		{
			temp->right=(*root)->right;
			*root=temp;
		}
		else
		{
			while((temp->right)->right!=NULL)
			{
				temp=temp->right;
			}
			*root=temp->right;
			temp->right=(*root)->left;
			(*root)->left=temp1->left;
			(*root)->right=temp1->right;
		}
	}
	freenode(temp1);
}
struct node* delete(struct node **root,int item)
{
	if(*root==NULL)
	{
		printf("\n\tThe item is not in the tree.\n");
	}
	else
	{
		if((*root)->data>item)
		{
			//printf("\n\tEntering the left of %d",(*root)->data);
			delete(&(*root)->left,item);
		}
		else if((*root)->data<item)
		{
			//printf("\n\tEntering the right of %d",(*root)->data);
			delete(&(*root)->right,item);
		}
		else
		{
			printf("\n\tItem found.\n");
			del(root);
			printf("\n\tItem deleted.\n");
			return NULL;
		}
	}
	return(*root);
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
int inorder(struct node **root)
{
	if(*root==NULL)
		return 0;
	inorder(&(*root)->left);
	printf("%d\t",(*root)->data);
	inorder(&(*root)->right);
	return 1;
}
int preorder(struct node **root)
{
	if(*root==NULL)
		return 0;
	printf("%d\t",(*root)->data);
	preorder(&(*root)->left);
	preorder(&(*root)->right);
	return 1;
}
int postorder(struct node **root)
{
	if(*root==NULL)
		return 0;
	postorder(&(*root)->left);
	postorder(&(*root)->right);
	printf("%d\t",(*root)->data);
	return 1;
}
int levelwise(struct node**root)
{
	int front=0,rear=1;
	return 0;
}
int mirror(struct node **root)
{
	if(*root==NULL)
		return 0;
	struct node* temp=(*root)->left;
	(*root)->left=(*root)->right;
	(*root)->right=temp;
	mirror(&(*root)->left);
	mirror(&(*root)->right);
	return 1;
}
int main()
{
	int ch=1,n;
	struct node* root=NULL;
	while (ch!=4)
	{
		printf("\n\tMENU::\n\t1.Insert\n\t2.Delete\n\t3.Display as Tree\n\t4.Display as Sequence\n\t5.Convert Tree into Mirror\n\t0.Exit\n\tEnter Choice::");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:	printf("\n\tEnter number::");
			scanf("%d",&n);
			insert(&root,n);
			break;
		case 2: printf("\n\tEnter number::");
			scanf("%d",&n);
			delete(&root,n);
			break;
		case 3:	printf("\n");
			display(&root,0);
			break;
		case 4: printf("\tDisplay Sub-MENU::\n\t1.Inorder\n\t2.Preorder\n\t3.Postorder\n\t4.Level-Wise\n\tEnter Choice::");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:inorder(&root);
					break;
				case 2:preorder(&root);
					break;
				case 3:postorder(&root);
					break;
				case 4:levelwise(&root);
					break;
				default:printf("Wrong Choice.");
			}
			break;
		case 5: mirror(&root);
			break;
		case 0: return 0;
			break;
		default:printf("\n\tInvalid Choice");
		}
	}
	return 0;
}
