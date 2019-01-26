/*C Program to Implement a Circular Queue using Linked List*/
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
int print(NODEPTR *front,NODEPTR *rear);//prints the whole linked list
//**********************************************************MAIN FUNCTION****************************************************************
int main()
{
	NODEPTR front=NULL,rear=NULL;
	int ch=0,tmp;
    system("clear");
	while(ch!=4)
    {
       	printf("\n\tMenu::\n\t1.Insert\n\t2.Delete\n\t3.Print\n\t4.Exit\n\tYour choice:: ");
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
            case 3: print(&front,&rear);
            		break;
            case 4: printf("\n\tProgram Terminated\n");
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
		
	/*Points next of rear to the front of the queue*/
	(*rear)->next=*front;
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
    else if((*front)->next==*front)
    {
    	*front=*rear=NULL;
    }
    else
    {
    	*front=(*front)->next;
    	(*rear)->next=*front;
    }
    int item =p->data;
    freenode(p);
    return item;
}
int print(NODEPTR *front,NODEPTR *rear)
{
	NODEPTR p=*front;
	int i=1;
	if(*front==NULL)
    {
    	printf("\n\tThe queue is empty");
    }
    else
    {
		printf("\n\tThe circular queue as of now is::");
		printf("\n\tPosition\tData\tAddress");
		while(p!=*rear)
		{
			printf("\n\t\t%d:\t%d\t%p",i++,p->data,p->next);
			p=p->next;
		}
		printf("\n\t\t%d:\t%d\t%p",i++,p->data,p->next);
		printf("\n");
	}
	return 0;
}
