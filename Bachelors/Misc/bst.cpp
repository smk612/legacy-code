#include <iostream>
#include <cstdlib>
using namespace std;

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
int notempty(struct qnode *front)
{
	if(front==NULL)
		return 0;
	else
		return 1;
}
int queuein(struct qnode **rear,struct node *inp)
{
	if(inp!=NULL)
	{
		cout<<"\nInserting-"<<inp->data;
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
		cout<<"\nDeleting-"<<(*front)->data->data;
		struct qnode *p=*front;
		(*front)=(*front)->next;
		free(p);
		p=NULL;
	}
	return 0;
}
int width=1;
void findwidth(struct node *root)
{
	struct qnode *temp=(struct qnode *)malloc(sizeof(struct qnode));
	temp->data=NULL;
	temp->next=NULL;
	struct qnode *front=(struct qnode *)malloc(sizeof(struct qnode));
	front->data=root;
	front->next=temp;
	struct qnode *rear=temp;
	while(notempty(front))
	{
		cout<<"123";
		if((front->data==NULL))
		//&&(front!=rear))
		{
			int w=0;cout<<"\nA";
			struct qnode *tmp=front;
			while(tmp!=rear)
			{
				w++;
				tmp=tmp->next;
			}
			if(w>width)
				width=w;
			rear->next=temp;
			rear=temp;
		}
		else
		{
		cout<<"4";	//if((front->data)->left!=NULL)
				queuein(&rear,(front->data)->left);
			//if((front->data)->right!=NULL)
				queuein(&rear,(front->data)->right);
		}cout<<"5";
		queuedel(&front);
	}
}
/*
struct snode
{
	struct node *data;
	struct snode *next;
};
class Stack
{
	struct snode* top;
	public:
		Stack();
		struct snode* allocnode(struct node* item);
		int push(struct node *inp);
		struct node* pop();
};
Stack::Stack()
{
	top=NULL;
}
struct snode* Stack::allocnode(struct node* item)
{
	struct snode* temp = (struct snode*)malloc(sizeof(struct snode));
	temp->data=item;
	temp->next=NULL;
	return temp;
}
int Stack::push(struct node* item)
{
	struct snode *inter=allocnode(item);
    
    	
    	if(inter==NULL)
    	{
       		cout<<"\n\tMemory couldnt be allocated from the heap. Overflow occurs.";
       		return 1;
    	}
    	if(top==NULL)
	{
		top=inter;
	}
	else
	{
		inter->next=top;
		top=inter;
	}
	return 0;
}
struct node* Stack::pop()
{
	struct snode* p = top;
    	struct node* item;
    
    	
    	if(top==NULL)
    	{
    		cout<<"\n\tUnderflow Occurs.";
    		return NULL;
    	}
    	else
    	{
    		top=top->next;     
     		item=p->data;
    		delete p;
    		return item;
    	}
}*/
int display(struct node **root,int level)
{
	int i=0;
	if(*root==NULL)
		return 0;
	display(&(*root)->right,level+1);
	for(i=0;i<=level;i++)
		cout<<"\t";
	cout<<(*root)->data<<endl;
	display(&(*root)->left,level+1);
	return 1;
}
int check(struct node *root)
{
	if(root==NULL)
		return 0;
	return 1;
}
struct node *pos=NULL;
struct node** parent(struct node *root,int item)
{
	pos=root;
	int flagl=check(pos->left),flagr=check(pos->right);cout<<"\nX"<<pos->data;
	while((pos!=NULL)&&(pos->data!=item))
	{
		cout<<"\nT"<<pos->data;
		if(pos->data>item)
		{
			if(flagl)
				pos=pos->left;
			else
				break;
		}
		if(pos->data<item)
		{
			if(flagr)
				pos=pos->right;
			else
				break;
		}
		flagl=check(pos->left);
		flagr=check(pos->right);
	}cout<<"\nY"<<pos->data;
	return &pos;
}
int insert(struct node **root,int item)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=item;
	temp->left=NULL;
	temp->right=NULL;
	if(*root==NULL)
	{
		*root=temp;
	}
	else
	{
		struct node **par=parent(*root,item);
		cout<<"parent-"<<(*par)->data;
		if((*par)->data>item)
		{
			(*par)->left=temp;
		}
		else if((*par)->data<item)
		{
			(*par)->right=temp;
		}
		else
		{
			cout<<"\n\tItem already present in tree.";
		}
	}
	return 1;
}
int main()
{
	int ch=1,n;
	struct node* root=NULL;
	while (ch!=0)
	{
		cout<<"\n\tMENU::\n\t1.Insert\n\t2.Display\n\t3.Convert Tree into Mirror\n\t4.Find the Width\n\t0.Exit\n\tEnter Choice::";
		cin>>ch;
		switch(ch)
		{
		case 1:	cout<<"\n\tEnter number::";
			cin>>n;
			insert(&root,n);
			break;
		case 2:	cout<<"\n";
			display(&root,0);
			break;
		case 3: //mirror(&root);
			break;
		case 4: findwidth(root);
			cout<<"\n\tThe width is-"<<width;
			break;
		case 0: return 0;
			break;
		default:cout<<"\n\tInvalid Choice";
		}
	}
	return 0;
}

