#include <stdio.h>
#define MAX 5
int stack[MAX];
int top=-1;
int is_full()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}
int is_empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void push(int n)
{
	if(is_full()==0)
	{
		top++;
		stack[top]=n;
	}
	else
		printf("\tThe Stack is Full.");
}
int pop()
{
	if(is_empty()==0)
	{
		return(stack[top--]);
	}
	else
		printf("\tThe Stack is Empty.");
	return -9999;	
}
int main()
{
	int ch,n;
	do
	{
		printf("\n\tMenu::\n\t1.Push\n\t2.Pop\n\t3.Is_Full\n\t4.Is_Empty\n\t5.Exit.\n\tEnter your Choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\tEnter number::");
				scanf("%d",&n);
				push(n);
				break;
			case 2: n=pop();
				if(n!=-9999)
					printf("\tThe element deleted is:: %d",n);
				break;
			case 3: if(is_full()==1)
					printf("\tThe Stack is full.");
				else
					printf("\tThe Stack is not full.");
				break;
			case 4: if(is_empty()==1)
					printf("\tThe Stack is empty.");
				else
					printf("\tThe Stack is not empty.");
				break;
			case 5: printf("\tProgram Terminated.\n");
				break;
			default: printf("\tInvalid Choice.");
		}
	}
	while(ch!=5);
	return 0;
}
