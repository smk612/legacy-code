/*C Program to Implement a Queue using Linked List*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node *NODEPTR;
NODEPTR allocate_node(int item);//Allocates memory space for a new node
int freenode(NODEPTR p);//Deallocates memory space
int insert(NODEPTR *front,NODEPTR *rear,int item);//creates a new node at rear, can also create start node if NULL is sent
int delete(NODEPTR *front,NODEPTR *rear);//deletes the node at front
//**********************************************************MAIN FUNCTION****************************************************************
int main()
{
	NODEPTR front=NULL,rear=NULL;
	int ch=0,tmp;
    system("clear");
	while(ch!=3)
    {
       	printf("\n\tMenu::\n\t1.Insert\n\t2.Delete\n\t3.Exit\n\tYour choice:: ");
        scanf("%d",&ch);
        switch(ch)
        {
        	case 1: printf("\n\tEnter data item:: ");
                  	scanf("%d",&tmp);
                  	insert(&front,&rear,tmp);
                  	break;
            case 2: tmp=delete(&front,&rear);
                	if(tmp!=-9999)
                		printf("\n\tThe item deleted is:: %d",tmp);
                   	break;
            case 3: printf("\n\tProgram Terminated\n");
               		exit(0);
               		break;
            default:printf("\n\tIncorrect value entered. Enter choice again");
        }
	}
	return 0;
}
//**********************************************************MEMBER FUNCTIONS*************************************************************
NODEPTR allocate_node(int item)
{
	NODEPTR temp = (NODEPTR)malloc(sizeof(struct Node));
	temp->data=item;
	temp->next=NULL;
	return temp;
}
int freenode(NODEPTR p)
{
    free(p);
    p=NULL;
    return 0;
}
int insert(NODEPTR *front,NODEPTR *rear,int item)
{
    NODEPTR inter=allocate_node(item);
	if(inter==NULL)
   	{
       	printf("\n\tMemory couldnt be allocated from the heap. Overflow occurs.");
       	return 1;
    	}
    if(*rear==NULL)
	{
		*front=*rear=inter;
	}
	else
	{
		(*rear)->next=inter;
		*rear=inter;
	}
	return 0;
}
int delete(NODEPTR *front,NODEPTR *rear)
{
    NODEPTR p = *front;
    if(*front==NULL)
    {
    	printf("\n\tThe queue is empty. Underflow occurs.");
    	return -9999;
    }
    else if((*front)->next==NULL)
    {
    	*front=*rear=NULL;
    }
    else
    {
    	*front=(*front)->next;
    }
    int item =p->data;
    freenode(p);
    return item;
}
