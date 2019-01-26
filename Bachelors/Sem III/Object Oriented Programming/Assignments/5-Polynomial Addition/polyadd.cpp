/*C++ Program to add two polynomials with the help of operator overloading*/
#include <iostream>
#include <cstdlib>
using namespace std;

struct Term
{
	int co,deg;
	struct Term *next;
};
typedef struct Term *POLY;
class Poly
{
	POLY start;
	public:
		Poly();
		POLY allocate_term(int,int);
		void input(); 
		Poly operator+(Poly);
		void print();
};
Poly::Poly()
{
	start=NULL;
}

/*Allocates memory space for a new term*/
POLY Poly::allocate_term(int co,int deg)
{
	POLY temp = (POLY)malloc(sizeof(struct Term));
	temp->co=co;
	temp->deg=deg;
	temp->next=NULL;
	return temp;
}

/*To take input of the polynomial*/
void Poly::input()
{
	char ch='Y';
	int i=1,co,de;
	while(ch=='Y'||ch=='y')
    {	
    	cout<<"\n\tEnter term no "<<i++<< ":";
    	cout<<"\n\tEnter coefficient::";
    	cin>>co;
    	cout<<"\tEnter degree::";
    	cin>>de;
    	if(co!=0)
    	{
    		POLY temp=allocate_term(co,de);
			if(start==NULL)
			{
				start=temp;
			}
			else
			{	
				POLY p=start,q;
				while((p!=NULL)&&((temp->deg)<(p->deg)))
				{
					q=p;
					p=p->next;
				}
				
				/*Adds the coefficients if the degrees are same*/
				if((p!=NULL)&&(temp->deg==p->deg))
					p->co=p->co+temp->co;
				else
				{
					temp->next=p;
					if(p==start)
						start=temp;
					else
						q->next=temp;
				}
			}
		}
		cout<<"\n\tDo you want to give another term? (Y/N)::";
		cin>>ch;	
   	}
   	print();
}

/*Adds the polynomials together*/
Poly Poly::operator+(Poly a)
{
	POLY p=start,q=a.start,temp;
	Poly ob;
	POLY r=ob.start;
	while(p!=NULL&&q!=NULL)
	{
		if((p->deg)>(q->deg))
		{
			temp=allocate_term(p->co,p->deg);
			p=p->next;
		}
		else if((p->deg)<(q->deg))
		{
			temp=allocate_term(q->co,q->deg);
			q=q->next;
		}
		else
		{
			if(p->co+q->co!=0)
				temp=allocate_term((p->co)+(q->co),p->deg);
			p=p->next;
			q=q->next;
		}
		if(r==NULL)
		{
			ob.start=r=temp;
		}
		else
		{
			r->next=temp;
			r=r->next;
		}
	}
	while(p!=NULL)
	{
		temp=allocate_term(p->co,p->deg);
		p=p->next;
		r->next=temp;
		r=r->next;
	}
	while(q!=NULL)
	{
		temp=allocate_term(q->co,q->deg);
		q=q->next;
		r->next=temp;
		r=r->next;
	}
	return ob;
}

/*prints the whole polynomial*/
void Poly::print()
{
	POLY p=start;
	if(p==NULL)
   	{
        	cout<<"\n\tThe polynomial doesnt exist";
   	}
   	else
    	{
		cout<<"\n\tThe polynomial as of now is::\n\t";
		while(p!=NULL)
		{	
			if(p->co!=1)
			{	
				if(p->deg==0)
					cout<<p->co;
				else
					cout<<(p->co)<<"x^"<<(p->deg);
			}
			else
				cout<<"x^"<<(p->deg);
			if((p->next!=NULL)&&((p->next->co)>0))
				cout<<"+";
			p=p->next;
			}
		cout<<"\n";
	}
}
int main()
{
	Poly a,b,c;
    	system("clear");
   	cout<<"\n\tEnter 1st polynomial:-";
    	a.input();
    	cout<<"\n\tEnter 2nd polynomial:-";
    	b.input();
    	c=a+b;
    	cout<<"\n\tThe First polynomial is::";
    	a.print();
   	cout<<"\n\tThe Second polynomial is::";
    	b.print();
    	cout<<"\n\tThe Final polynomial is::";
    	c.print();
	return 0;
}


