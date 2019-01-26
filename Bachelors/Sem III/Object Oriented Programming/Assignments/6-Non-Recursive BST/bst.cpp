#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
struct node
{
	T data;
	struct node<T> *left;
	struct node<T> *right;
};

/**************************Converting into a Mirror*************************/
template <class T>
struct snode
{
	struct node<T> *data;
	struct snode<T> *next;
};
template <class T>
class Tree
{
	struct node<T>* root;
	public:
		Tree()
		{
			root=NULL;
		}
		void insert();
		void indisplay();
		void mirror();
		void findwidth();
		void menu();
};
template <class T>
class Stack
{
	struct snode<T>* top;
	public:
		Stack();
		struct snode<T>* allocnode(struct node<T>* item);
		void push(struct node<T> *inp);
		struct node<T>* pop();
		int empty()
		{
			if(top==NULL)
				return 1;
			return 0;
		}
};
template <class T>
Stack<T>::Stack()
{
	top=NULL;
}
template <class T>
struct snode<T>* Stack<T>::allocnode(struct node<T>* item)
{
	struct snode<T>* temp = (struct snode<T>*)malloc(sizeof(struct snode<T>));
	temp->data=item;
	temp->next=NULL;
	return temp;
}
template <class T>
void Stack<T>::push(struct node<T>* item)
{
	struct snode<T> *inter=allocnode(item);
       	if(inter==NULL)
    	{
       		cout<<"\n\tMemory couldnt be allocated from the heap. Overflow occurs.";
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
}
template <class T>
struct node<T>* Stack<T>::pop()
{
	struct snode<T>* p = top;
    	struct node<T>* item;
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
}

/* Mirror the tree using stack*/
template <class T>
void Tree<T>::mirror()
{
    	if(root==NULL)
    		return;
    	Stack<T> s;
    	s.push(root);
    	while(!s.empty())
    	{
    		struct node<T> *curr=s.pop();
    		
    		//Swap the children
    		struct node<T> *temp=curr->right;
    		curr->right=curr->left;
    		curr->left=temp;
    		
    		//Push the children on the stack
    		if(curr->right)
    			s.push(curr->right);
    		if(curr->left)
    			s.push(curr->left);
    	}
}

/***********************Finding the width of the tree*************************/
template <class T>
struct qnode
{
	struct node<T> *data;
	struct qnode<T> *next;
};
template <class T>
int queuein(struct qnode<T> **rear,struct node<T> *inp)
{
	if(inp!=NULL)
	{
		struct qnode<T> *temp=(struct qnode<T> *)malloc(sizeof(struct qnode<T>));
		temp->data=inp;
		temp->next=NULL;
		(*rear)->next=temp;
		*rear=temp;
	}
	return 0;
}
template <class T>
int queuedel(struct qnode<T> **front)
{
	struct qnode<T> *p=*front;
	(*front)=(*front)->next;
	free(p);
	p=NULL;
	return 0;
}
template <class T>
void Tree<T>::findwidth()
{
	if(root==NULL)
	{
		cout<<"\n\tThe width is-0"<<endl;
		return;
	}
	static int width=1;
	struct qnode<T> *front=NULL;
	struct qnode<T> *rear=(struct qnode<T> *)malloc(sizeof(struct qnode<T>));
	rear->data=root;
	rear->next=NULL;
	front=rear;
	rear=(struct qnode<T> *)malloc(sizeof(struct qnode<T>));
	rear->data=NULL;
	rear->next=NULL;
	front->next=rear;	
	while(front!=rear)
	{
		if(front->data==NULL)
		{
			int w=0;
			struct qnode<T> *tmp=front;
			while(tmp!=rear)
			{
				w++;
				tmp=tmp->next;
			}
			if(w>width)
				width=w;
			tmp=(struct qnode<T> *)malloc(sizeof(struct qnode<T>));
			tmp->data=NULL;
			tmp->next=NULL;
			rear->next=tmp;
			rear=tmp;
		}
		else
		{
			queuein(&rear,(front->data)->left);
			queuein(&rear,(front->data)->right);
		}
		queuedel(&front);
	}
	cout<<"\n\tThe width is-"<<width<<endl;
}

/***********************************Creating the Tree***************************/
template <class T>
int check(struct node<T> *root)
{
	if(root==NULL)
		return 0;
	return 1;
}
template <class T>
struct node<T>* parent(struct node<T> *root,int item)
{
	struct node<T> *pos=root;
	while((pos!=NULL)&&(pos->data!=item))
	{
		if(pos->data>item)
		{
			if(check(pos->left))
				pos=pos->left;
			else
			   break;	
			
		}
		if(pos->data<item)
		{
			if(check(pos->right))
				pos=pos->right;
			else
			   break;	
		}
		
	}
	return pos;
}
template <class T>
void Tree<T>::insert()
{
	T item;
	cout<<"\n\tEnter data::";
	cin>>item;
	struct node<T> *temp=(struct node<T> *)malloc(sizeof(struct node<T>));
	temp->data=item;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node<T> *par=parent(root,item);
		if((par)->data>item)
		{
			(par)->left=temp;
		}
		else if((par)->data<item)
		{
			(par)->right=temp;
		}
		else
		{
			cout<<"\n\tItem already present in tree.";
		}
	}
}

/***********************************Displaying the Tree***************************/
template <class T>
void Tree<T>::indisplay()
{
	Stack<T> S;
	struct node<T> *temp=root;
	cout<<"\n\tInorder Display of Tree::\n\t";
	while(1)
	{
		while(temp!=NULL)
		{
			S.push(temp);
			temp=temp->left;
		}
		if(S.empty())
			break;
		temp=S.pop();
		cout<<temp->data<<"\t";
		temp=temp->right;
	}
	cout<<endl;
}
template <class T>
void Tree<T>::menu()
{
	int ch=1;
	while (ch!=0)
	{
		cout<<"\n\tMENU::\n\t1.Insert\n\t2.Inorder Display\n\t3.Convert Tree into Mirror\n\t4.Find the Width\n\t0.Exit\n\tEnter Choice::";
		cin>>ch;
		switch(ch)
		{
		case 1:	insert();
			break;
		case 2:	indisplay();
			break;
		case 3: mirror();
			break;
		case 4: findwidth();
			break;
		case 0: cout<<"\n\tProgram Terminated."<<endl;
			break;
		default:cout<<"\n\tInvalid Choice.";
		}
	}
}
/***********************************The Main Function******************************/
int main()
{
	int ch=1;
	cout<<"\n\tChoose the datatype that you want to work with::\n\t1.Integer\n\t2.Float\n\t3.Character\n\tEnter Choice::";
	cin>>ch;
	switch(ch)
	{
		case 1:{Tree<int> t;
			t.menu();}
			break;
		case 2:	{Tree<float> t;
			t.menu();}
			break;
		case 3:	{Tree<char> t;
			t.menu();}
			break;
		default:cout<<"\n\tInvalid Choice."<<endl;
	}
	return 0;
}
