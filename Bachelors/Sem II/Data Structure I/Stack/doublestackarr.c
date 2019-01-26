#include <stdio.h>
#include <stdlib.h>
int push1(int *stk,int *top1,int *top2,int item);
int push2(int *stk,int *top1,int *top2,int item);
int pop1(int *stk,int *top1,int lbound);
int pop2(int *stk,int *top2,int lbound);
//int printstks(int *stk,int *top1,int *top2,int ubound);
int main()
{
	int top1=-1,top2,ch=1,cho=0,n,item;
	system("clear");
	printf("\n\tEnter size of array for creating 2 stacks::");
	scanf("%d",&n);
	//int *stk=(int*)malloc(n*sizeof(int));
	int stk[n];
	top2=n;
	while(ch!=4)
	{	
		printf("\n\tMenu::\n\t1.Use Stack 1\n\t2.Use Stack 2\n\t3.Print\n\t4.Exit\n\tYour choice:: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n\t1.Push in stack 1\n\t2.Pop from stack 1\n\tEnter Choice::");
				scanf("%d",&cho);
				if(cho==1)
				{	
					printf("\n\tEnter item::");
					scanf("%d",&item);
					push1(stk,&top1,&top2,item);
				}
				else
				{
					item=pop1(stk,&top1,-1);
					if(item==99999)
					{
						printf("\n\tOperation Failed");
					}
					else
					{
						printf("\n\tItem popped is %d",item);
					}	
				}
				break;
			case 2:printf("\n\t1.Push in stack 2\n\t2.Pop from stack 2\n\tEnter Choice::");
				scanf("%d",&cho);
				if(cho==1)
				{	
					printf("\n\tEnter item for stack 2::");
					scanf("%d",&item);
					push2(stk,&top1,&top2,item);
				}
				else
				{
					item=pop2(stk,&top2,n);
					if(item==99999)
					{
						printf("\n\tOperation Failed");
					}
					else
					{
						printf("\n\tItem popped is %d",item);
					}
				}
				break;
			//case 3:printstks(stk,&top1,&top2,n-1);	
				break;
			default:printf("\n\tProgram Terminated\n");
		}
	}
	return 0;
}
int push1(int *stk,int *top1,int *top2,int item)
{
	if((*top1)+1==(*top2))
	{
		printf("\n\tOverflow in stack 1");
	}
	else
	{
		(*top1)=(*top1)+1;
		stk[(*top1)]=item;
	}
	return 0;
}
int push2(int *stk,int *top1,int *top2,int item)
{
	if((*top2)-1==(*top1))
	{
		printf("\n\tOverflow in stack 2");
	}
	else
	{
		(*top2)=(*top2)-1;
		stk[(*top2)]=item;
	}
	return 0;
}
int pop1(int *stk,int *top1,int lbound)
{
	if((*top1)==lbound)
	{
		printf("\n\tUnderflow in stack 1");
		return 99999;
	}
	else
	{
		int item=stk[(*top1)];
		(*top1)=(*top1)-1;
		return item;
	}
}
int pop2(int *stk,int *top2,int lbound)
{
	if((*top2)==lbound)
	{
		printf("\n\tUnderflow in stack 2");
		return 99999;
	}
	else
	{
		int item=stk[(*top2)];
		(*top2)=(*top2)+1;
		return item;
	}
}
/*int printstks(int *stk,int *top1,int *top2,int ubound)
{
	int i;
	printf("\n\tStack 1");
	for(i=0;i<=(*top1);i++)
	{
		printf("\n\t%d\t%d",i,stk[i]);
	}
	printf("\n\tStack 2");
	for(i=ubound;i>=(*top2);i--)
	{
		printf("\n\t%d\t%d",i,stk[i]);
	}
}*/
