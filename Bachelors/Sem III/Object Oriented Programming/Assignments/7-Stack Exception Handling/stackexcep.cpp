/*C++ Program to implement classes Stack and MyStack using Excpetion Handling.*/
#include<iostream>
using namespace std;

/*Class Stack and its associated functions*/
class Stack
{
	int *stk,max,top;
	public:
		
		/*Function to implement pushing an element into the Stack*/
		virtual void push(int x)
		{ 
			stk[++top]=x;
		}
		
		/*Function to implement popping an element from Stack*/
		virtual int pop()
		{
			cout<<"\n\tItem popped is "<<stk[top--]<<endl;
			return 0;
		}
};

/*Class MyStack and its associated functions*/
class MyStack:public Stack
{
	int *stk,max,top;
	public:
		
		/*Parameterised constructor of class MyStack*/
		MyStack(int n)
		{
			stk=new int[n];
			max=n;
			top=-1;
		}
		
		/*Overriding Function to implement pushing an element into the Stack*/
		void push(int x)
		{
			try
			{
				if(top+1==max)
					throw "Overflow";
				else
				{
					stk[++top]=x;
				}
			}
			catch(const char* s)
			{
				cout<<"\n\tOverflow"<<endl;
			}
		}

		/*Overriding Function to implement popping an element from Stack*/
		int pop()
		{
			try
			{
				if(top==-1)
					throw "Underflow";
				else
				{
					cout<<"\n\tItem popped is "<<stk[top--]<<endl;
				}
			}
			catch(const char *s)
			{
				cout<<"\n\tUnderflow"<<endl;
			}
			return 0;
		}

};

int main()
{
	int ch=0,n;
	cout<<"\n\tEnter size of Stack:";
	cin>>n;
		
	/*Creating an object of class MyStack*/
	MyStack stk(n);
	do
	{
	
		/*Menu for implementing Stack functions*/
		cout<<"\n\tMenu for Stack::\n\t1.Push\n\t2.Pop\n\t3.Exit\n\tYour Choice::";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\n\tEnter the item to be pushed:";
				cin>>n;
				stk.push(n);
				break;
			case 2: stk.pop();
				break;
			case 3: cout<<"\n\tProgram Terminated.\n";
				break;	
			default:cout<<"\n\tInvalid Choice.";
		}
	}
	while(ch!=3);
	return 0;
}
