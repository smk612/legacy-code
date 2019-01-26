#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int co,deg;
	struct Node *next;
};
typedef struct Node *POLY;
POLY allocate_node(int co,int deg);//Allocates memory space for a new node
int input(POLY *start);//To take input of the polynomial
int print(POLY *start);//prints the whole linked list
//**********************************************************MAIN FUNCTION****************************************************************
int main()
{
	POLY start1=NULL,start2=NULL,startfin=NULL;
    system("clear");
   	printf("\n\tEnter 1st polynomial:-");
    input(&start1);
    printf("\n\tEnter 2nd polynomial:-");
    input(&start2);
    polynomialadd(&start1,&start2,&startfin);
    printf("\n\tThe First polynomial is::");
    print(&start1);
    printf("\n\tThe Second polynomial is::");
    print(&start2);
    printf("\n\tThe Final polynomial is::");
    print(&startfin);
	return 0;
}
//**********************************************************MEMBER FUNCTIONS*************************************************************
POLY allocate_node(int co,int deg)
{
	POLY temp = (POLY)malloc(sizeof(struct Node));
	temp->co=co;
	temp->deg=deg;
	temp->next=NULL;
	return temp;
}
int input(POLY *start)
{
	char ch='Y';
	int i=1,co,de;
	while(ch=='Y'||ch=='y')
    {	
    	printf("\n\tEnter term no %d:",i++);
    	printf("\n\tEnter coefficient::");
    	scanf("%d",&co);
    	printf("\tEnter degree::");
    	scanf("%d",&de);
    	POLY temp=allocate_node(co,de);
		if(*start==NULL)
		{
			*start=temp;
		}
		else
		{	
			POLY p=*start,q;
			while((p!=NULL)&&((temp->deg)<(p->deg)))
			{
				q=p;
				p=p->next;
			}
			temp->next=p;
			if(p==*start)
				*start=temp;
			else
				q->next=temp;
		}
		printf("\n\tDo you want to give another term? (Y/N)::");
		getchar();
		scanf("%c",&ch);
		print(&(*start));	
   	}
	return 0;
}
int polynomialadd(POLY *start1,POLY *start2,POLY *startfin)
{
	POLY p=*start1,q=*start2,r=*startfin,temp;
	while(p!=NULL&&q!=NULL)
	{
		if((p->deg)>(q->deg))
		{
			temp=allocate_node(p->co,p->deg);
			p=p->next;
		}
		else if((p->deg)<(q->deg))
		{
			temp=allocate_node(q->co,q->deg);
			q=q->next;
		}
		else
		{
			temp=allocate_node((p->co)+(q->co),p->deg);
			p=p->next;
			q=q->next;
		}
		if(r==NULL)
		{
			(*startfin)=r=temp;
		}
		else
		{
			r->next=temp;
			r=r->next;
		}
	}
	while(p!=NULL)
	{
		temp=allocate_node(p->co,p->deg);
		p=p->next;
		r->next=temp;
		r=r->next;
	}
	while(q!=NULL)
	{
		temp=allocate_node(q->co,q->deg);
		q=q->next;
		r->next=temp;
		r=r->next;
	}
	return 0;
}
int print(POLY *start)
{
	POLY p=*start;
	int i=1;
	if(p==NULL)
   	{
        	printf("\n\tThe polynomial doesnt exist");
   	}
   	else
   	{
		printf("\n\tThe linked list as of now is::");
		printf("\n\tPosition\tCoefficient\tDegree\tAddress");
		while(p!=NULL)
		{
			printf("\n\t\t%d:\t%d\t\t%d\t%p",i++,p->co,p->deg,p->next);
			p=p->next;
		}
		printf("\n");
	}
	return 0;
}
