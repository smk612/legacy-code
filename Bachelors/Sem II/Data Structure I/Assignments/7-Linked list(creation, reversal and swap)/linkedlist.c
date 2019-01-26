/*C Program to Create a linked list and also have functions for reversing the linked list and swapping kth and (k+1)th node*/
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
int create_node(NODEPTR *start,int item);//creates a new node, can also create start node if NULL is sent
int delete_node(NODEPTR *start,int pos);//deletes the node at position pos
int swapk(NODEPTR *start,int k);//swaps nodes k and k+1
int reverse(NODEPTR *start);//reverses the whole linked list;
int print(NODEPTR *start);//prints the whole linked list
//**********************************************************MAIN FUNCTION****************************************************************
int main()
{
    NODEPTR start=NULL;
    int ch=0,tmp;
    system("clear");
    while(ch!=6)
    {
        printf("\n\tMenu::\n\t1.Insert\n\t2.Delete\n\t3.Swap elements at k and k+1\n\t4.Reverse the list\n\t5.Print\n\t6.Exit\n\tYour choice:: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n\tEnter data item:: ");
                   scanf("%d",&tmp);
                   create_node(&start,tmp);
                   print(&start);
                   break;
            case 2:print(&start);
                   if(start!=NULL)
                   {
                  		printf("\n\tEnter position to be deleted:: ");
                  	 	scanf("%d",&tmp);
                  		delete_node(&start,tmp);
                   		print(&start);
                   }
                   break;
            case 3:printf("\n\tList before swapping");
            	   print(&start);
                   printf("\n\tEnter k:: ");
                   scanf("%d",&tmp);
            	   swapk(&start,tmp);
            	   printf("\n\tList after swapping");
            	   print(&start);
            	   break;
            case 4:printf("\n\tList before reversal");
            	   print(&start);
            	   reverse(&start);
            	   printf("\n\tList after reversal");
            	   print(&start);
            	   break;
            case 5:print(&start);
                   break;
            case 6:printf("\n\tProgram Terminated\n");
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
int create_node(NODEPTR *start,int item)
{
    NODEPTR inter=allocate_node(item);
	if(*start==NULL)
	{
		*start=inter;
	}
	else
	{
		NODEPTR p=*start;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=inter;
	}
	return 0;
}
int delete_node(NODEPTR *start,int pos)
{
    NODEPTR p = *start;
    if(pos==1)
    {
        *start=(*start)->next;
        freenode(p);
    }
    else
    {
        NODEPTR q=*start;
        int i;
        for(i=1;i<pos;i++)
        {
            q=p;
            
            /*Checks if user inputs wrong position*/
            if(p==NULL)
            {
            	printf("\n\tPosition entered exceeds number of nodes.");
            	return 1;
            }
            p=p->next;
        }
        q->next=p->next;
        freenode(p);
       
    }
    return 0;
}
int swapk(NODEPTR *start,int k)
{
	NODEPTR p=*start;
	int i;
	
	/*Checks if no node exists*/
	if(p==NULL)
	{
		printf("\n\tCannot swap as no node exists.");
		return 1;
	}
	
	/*Checks if 1st node but not the last node*/
	if((k==1)&&((*start)->next!=NULL))
	{
		*start=p->next;
		p->next=(p->next)->next;
		(*start)->next=p;
	}
	else
	{
		NODEPTR q=*start;
		for(i=1;i<k;i++)
		{
			q=p;
			p=p->next;
		}
		if(p->next!=NULL)
		{
			q->next=p->next;
			p->next=(p->next)->next;
			(q->next)->next=p;
		}
		
		/*Checks if last node*/
		else
			printf("\n\tk+1th node doesn't exist. Swapping not possible.");
	}
	return 0;
}
int reverse(NODEPTR *start)
{
	NODEPTR p=*start,q=*start;
	while((q->next)!=NULL)
	{
		p=q;
		p=q->next;
		q->next=p->next;
		p->next=*start;
		*start=p;
	}
	return 0;
}
int print(NODEPTR *start)
{
	NODEPTR p=*start;
	int i=1;
	if(*start==NULL)
    {
        printf("\n\tThe list is empty");
    }
    else
    {
	printf("\n\tThe linked list as of now is::");
	printf("\n\tPosition\tData\tAddress");
		while(p!=NULL)
		{
			printf("\n\t\t%d:\t%d\t%p",i++,p->data,p->next);
			p=p->next;
		}
	printf("\n");
	}
	return 0;
}
