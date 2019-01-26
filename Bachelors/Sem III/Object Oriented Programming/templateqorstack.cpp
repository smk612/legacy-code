/*C++ Program to implement a Stack or Queue using 1D array applying the concept of class.*/
#include <iostream>
#include <cstdlib>
using namespace std;

/*Class Stack and its associated functions*/
template <class T>
class Stack
{
	T *stk;
	int max,top;
	public:
		Stack(int);
		void push(T);
		T pop();
};

/*Parameterised constructor of class Stack*/
template <class T>
Stack<T>::Stack(int n)
{
	stk=new T[n];
	max=n;
	top=-1;
}

/*Function to implement pushing an element into the Stack*/
template <class T>
void Stack<T>::push(T x)
{
	if(top+1==max)
		cout<<"\n\tOverflow"<<endl;
	else
	{
		stk[++top]=x;
	}
}

/*Function to implement popping an element from Stack*/
template <class T>
T Stack<T>::pop()
{
	T item=(T)NULL;
	if(top==-1)
		cout<<"\n\tUnderflow"<<endl;
	else
	{
		item=stk[top];
		cout<<"\n\tItem popped is "<<stk[top--]<<endl;
	}
	return item;
}

/*Class Queue and its associated functions*/
template <class S>
class Queue
{
	S *q;
	int max,front,rear;
	public:
		Queue(int);
		void insert(S);
		S del();
		void display()
		{
			if(front+1==rear)
				cout<<"\n\tQueue is empty"<<endl;
			for(int i=front+1;i<rear;i++)
			{
				cout<<"\t"<<q[i]<<endl;
			}
		}
};

/*Parameterised constructor of class Queue*/
template <class S>
Queue<S>::Queue(int n)
{
	q=new S[n];
	max=n;
	rear=0;
	front=-1;
}

/*Function to implement insertion into a Queue*/
template <class S>
void Queue<S>::insert(S x)
{
	if(rear==max)
	{
	
		/*Correcting the Inchworm Effect*/
		if(front!=-1)
		{
			for(int i=0;i<rear;i++)
				q[i]=q[i+front+1];
			rear=rear-(front+1);
			front=-1;
			q[rear++]=x;
		}
		else
			cout<<"\n\tQueue is full."<<endl;
	}
	else
		q[rear++]=x;
}

/*Function to implement deletion from a Queue*/
template <class S>
S Queue<S>::del()
{
	S item=(S)NULL;
	if(front+1==rear)
		cout<<"\n\tQueue is empty.";
	else
	{
		item=q[front];
		++front;
	}
	return item;
}
int main()
{
	int ch=0;
	int n;
	
	/*Asking the user whether to create a Stack or a Queue*/
	cout<<"\n\tCreation Menu::\n\t1.Stack\n\t2.Queue\n\tYour Choice::";
	cin>>ch;
	switch(ch)
	{
		case 1: {
			cout<<"\n\tEnter size of Stack:";
			cin>>n;
			
			/*Creating an object of class Stack*/
			Stack<int> stk(n);
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
			}
			break;
		case 2: {
			cout<<"\n\tEnter size of Queue:";
			cin>>n;
			
			/*Creating an object of class Queue*/
			Queue<int> q(n);
			do
			{
				
				/*Menu for implementing Queue functions*/
				cout<<"\n\tMenu for Queue::\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Exit\n\tYour Choice::";
				cin>>ch;
				switch(ch)
				{
					case 1: cout<<"\n\tEnter the item to be inserted:";
						cin>>n;
						q.insert(n);
						break;
					case 2: q.del();
						break;
					case 3: q.display();
						break;
					case 4: cout<<"\n\tProgram Terminated.\n";
						break;	
					default:cout<<"\n\tInvalid Choice.";
				}
			}
			while(ch!=4);
			}
			break;
		default:cout<<"\n\tInvalid Choice.";		
	}
	return 0;
}
