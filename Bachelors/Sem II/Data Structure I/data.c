#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node* allocate_Node(int);
void insert(struct Node *);
void display(struct Node *);
void mid(struct Node *);
struct Node* deletion_position(struct Node *,int);
struct Node* deletion_element(struct Node *,int);	
struct Node* insert_position(struct Node *,int);
struct Node* reversal(struct Node *);

int main()
{
	int choice,item,pos,element;
	printf("Enter the item to be inserted::");
	scanf("%d",&item);
	struct Node *start=NULL;
	start=allocate_Node(item);
	do
	{
		printf("----------MENU----------\n\t1.INSERT\n\t2.DISPLAY\n\t3.MIDPOINT\n\t4.DELETION POSITIONWISE\n\t5.DELETION ELEMENTWISE\n\t6.INSERT POSITIONWISE\n\t7.REVERSAL\n\t8.EXIT\n");
		printf("Enter your choice::");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert(start);
					break;
			case 2: printf("Elements of the list are::");
					display(start);
					break;
			case 3: mid(start);
					break;		
			case 4: printf("Enter the position::");
					scanf("%d",&pos);
					start=deletion_position(start,pos);
					break;
			case 5: printf("Enter the element::");
					scanf("%d",&element);
					start=deletion_element(start,element);
					break;
			case 6:	printf("Enter the position::");
					scanf("%d",&pos);
					start=insert_position(start,pos);
					break;
			case 7:	start=reversal(start);
					break;
			case 8: exit(0);				
		}
	}while(choice>=1||choice<=8);
	return 0;	
}

struct Node* allocate_Node(int item)
{
	struct Node *temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=item;
	temp->next=NULL;
	return temp;
}

void insert(struct Node *start)
{
	int item;
	struct Node *p,*temp;
	printf("Enter the item to be inserted::");
	scanf("%d",&item);
	if(start==NULL)
		start=allocate_Node(item);
	else
	{
		temp=allocate_Node(item);
		p=start;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
}	

void display(struct Node *start)
{
	struct Node *p;
	p=start;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;				
	}
	printf("\n");
}

void mid(struct Node *start)
{
	int c=1;
	struct Node *p,*q;
	p=start;
	q=start;
	while(p->next!=NULL)
	{
		if(c%2==0)
			q=q->next;
		p=p->next;
		c+=1;
	}
	printf("%d",q->data);				
}	

struct Node* deletion_position(struct Node *start,int pos)
{
	struct Node *p,*q;
	p=q=start;
	int i;
	if(pos==1)
	{
		start=start->next;
		free(p);
		p=NULL;
		return start;
	}
	else
	{
		for(i=1;i<pos;i++)
		{
			q=p;
			p=p->next;
		}	
		if(p->next==NULL)
		{
			q->next=NULL;
			free(p);
			p=NULL;
			return start;
		}
		else
		{
			q->next=p->next;
			free(p);				
			p=NULL;
			return start;
		}
		
	}
}	

struct Node* deletion_element(struct Node *start,int element)
{
	struct Node *p,*q;
	p=q=start;
	if(p->data==element)
	{
		start=start->next;
		free(p);
		p=NULL;
		return start;
	}
	else
	{	
		p=p->next;
		while(p->data!=element)						
		{
			p=p->next;
			q=q->next;
		}
		if(p->next==NULL)
		{
			q->next=NULL;
			free(p);
			p=NULL;
			return start;
		}
		else
		{
			q->next=p->next;
			free(p);				
			p=NULL;
			return start;
		}
	}
}		

struct Node* insert_position(struct Node *start,int pos)
{
	struct Node *p,*q,*temp;
	int i,item;
	p=q=start;
	printf("Enter the item to be inserted::");
	scanf("%d",&item);
	if(pos==1)
	{
		temp=allocate_Node(item);
		temp->next=p;
		return temp;
	}
	else
	{
		for(i=1;i<pos;i++)	
		{
			q=p;
			p=p->next;
		}
		if(q->next==NULL)
		{
			printf("mohit");
			temp=allocate_Node(item);
			q->next=temp;
			return start;
		}
		else
		{		
			temp=allocate_Node(item);
			temp->next=q->next;
			q->next=temp;
			return start;
		}
	}
}	

struct Node* reversal(struct Node *start)
{
	struct Node *p,*q;
	p=q=start;
	p=start->next;
	start->next=NULL;
	while(p!=NULL)
	{
		q=p->next;
		p->next=start;
		start=p;
		p=q;
	}
	
	display(start);
	//start=p;
	return start;
}							
