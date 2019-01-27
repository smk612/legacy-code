#include <stdio.h>
#define MAX 5
int q[MAX];
int front=0,rear=0;
int is_full()
{
	if((rear+1)%MAX==front)
		return 1;
	else
		return 0;
}
int is_empty()
{
	if(front==rear)
		return 1;
	else
		return 0;
}
void enqueue(int n)
{
	if(is_full()==0)
	{
		q[rear]=n;
		rear=(rear+1)%MAX;
	}
	else
		printf("\tThe Queue is Full.");
}
int dequeue()
{
	if(is_empty()==0)
	{
		int x=q[front];
		front=(front+1)%MAX;
		return x;
	}
	else
		printf("\tThe Queue is Empty.");
	return -9999;	
}
int main()
{
	int ch,n;
	do
	{
		printf("\n\tMenu::\n\t1.Enqueue\n\t2.Dequeue\n\t3.Is_Full\n\t4.Is_Empty\n\t5.Exit.\n\tEnter your Choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\tEnter number::");
				scanf("%d",&n);
				enqueue(n);
				break;
			case 2: n=dequeue();
				if(n!=-9999)
					printf("\tThe element deleted is:: %d",n);
				break;
			case 3: if(is_full()==1)
					printf("\tThe Queue is full.");
				else
					printf("\tThe Queue is not full.");
				break;
			case 4: if(is_empty()==1)
					printf("\tThe Queue is empty.");
				else
					printf("\tThe Queue is not empty.");
				break;
			case 5: printf("\tProgram Terminated.\n");
				break;
			default: printf("\tInvalid Choice.");
		}
	}
	while(ch!=5);
	return 0;
}
