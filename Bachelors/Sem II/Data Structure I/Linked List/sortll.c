#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node *NODEPTR;
NODEPTR allocate_node(int item);//Allocates memory space for a new node
int print(NODEPTR *start);//prints the whole linked list
//**********************************************************MAIN FUNCTION****************************************************************
int main()
{
    NODEPTR start=NULL;
    system("clear");
    int item;
    char ch='Y';
    print(&start);
    while(ch=='Y'||ch=='y')
    {	
    	printf("\n\tEnter the item to be inserted in sorted order::");
    	scanf("%d",&item);
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
	printf("\n\tDo you want to insert again? (Y/N)::");
	getchar();
	scanf("%c",&ch);
	print(&start);	
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
