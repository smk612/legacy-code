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
int print(NODEPTR *start);//prints the whole linked list
//**********************************************************MAIN FUNCTIONS***************************************************************
int main()
{
    NODEPTR start;
    int ch=0,tmp;
    system("clear");
    while(ch!=4)
    {
        printf("\n\tMenu::\n\t1.Insert\n\t2.Delete\n\t3.Print\n\t4.Exit\n\tYour choice:: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n\tEnter data item:: ");
                   scanf("%d",tmp);
                   create_node(&start,tmp);
                   print(&start);
                   break;
            case 2:print(&start);
                   printf("\n\tEnter position to be deleted:: ");
                   scanf("%d",tmp);
                   delete_node(&start,tmp);
                   print(&start);
                   break;
            case 3:print(&start);
                   break;
            case 4:printf("\n\tProgram terminated");
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
    if(*start==NULL)
    {
        printf("\n\tThe list is empty");
        return 0;
    }
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
            p=p->next;
        }
        if((p->next)->next==NULL)
        {
            p->next=NULL;
            freenode(p);
        }
        else
        {
            q->next=p->next;
            freenode(p);
        }
    }
    return 0;
}
int print(NODEPTR *start)
{
	NODEPTR p=*start;
	int i=0;
	printf("\n\tThe linked list as of now is::");
	while(p!=NULL)
	{
		printf("\n\t%d:%d",i++,p->data);
		p=p->next;
	}
	return 0;
}
