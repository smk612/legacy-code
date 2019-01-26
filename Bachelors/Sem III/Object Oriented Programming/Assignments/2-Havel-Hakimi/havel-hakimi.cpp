/*C++ Program to implement the Havel-Hakimi Algorithm for Testing the existence of a Graph.*/
#include<iostream>
using namespace std;

/*Class Degseq and its associated functions*/
class Degseq
{
	int l;
	public:
		int *seq;
		Degseq(int);
		~Degseq();
		void decsort(int);
		int checkzero(int);
		void display(int m)
		{
			for(int i=m;i<l;i++)
			{
				cout<<"\t"<<seq[i];
			}
			cout<<endl;
		}
};

/*Parameterised Constructor*/
Degseq::Degseq(int i)
{
	l=i;
	seq=new int[l];
}

/*Destructor*/
Degseq::~Degseq()
{
	delete []seq;
}

/*Function to sort the remaining degree sequence*/
void Degseq::decsort(int m)
{
	int i,j,key;
	for(i=m+1;i<l;i++)
	{
		key=seq[i];
		for(j=i-1;(j>=0)&&(seq[j]<key);j--)
		{
			seq[j+1]=seq[j];
		}
		seq[j+1]=key;//inserts the key at proper position
	}
	display(m);
}

/*Returns -1 if negative degree exists, 0 if positive degree exists or 1 if all elements are zero*/
int Degseq::checkzero(int m)
{
	int i;
	for(i=m;i<l;i++)
	{
		if(seq[i]<0)
			return -1;
		else if(seq[i]>0)
			return 0;
		else
			continue;	
	}
	return 1;//all are zero
}
int main()
{
	int l,i,c=0,k;
	cout<<"\n\tEnter the number of vertices::";
	cin>>l;
	Degseq ob(l);
	cout<<"\n\tEnter non-negative degree sequence.\n\t";
	
	/*Checks if any degree is greater than the number of vertices*/
	for(i=0;i<l;i++)
	{
		cin>>ob.seq[i];
		if(ob.seq[i]%2)
			c++;
		if(ob.seq[i]>=l)
		{
			cout<<"\n\tGraph Not Possible: Degree greater than equal to number of vertices."<<endl;
			return 1;
		}
	}
	
	/*Checks for even number of odd degree vertices*/
	if(c%2)
	{
		cout<<"\n\tGraph Not Possible: Odd number of odd degrees present."<<endl;
		return 1;
	}
	c=0;
	
	/*Performs the Havel-Hakimi according to the algorithm*/
	while(ob.checkzero(c)==0)
	{
		
		/*Reorder degree sequence in non-increasing order*/
		ob.decsort(c);
		
		/*Let k = first element in degree sequence*/
		k=ob.seq[c];
		c++;
		
		/*Subtract 1 from the next k terms*/
		for(i=c;k>0;ob.seq[i]--,i++,k--);
		
	}
	
	/*Final step to Check the existence of the graph*/
	if(ob.checkzero(c)==-1)
		cout<<"\n\tGraph Not Possible: Degree is negative."<<endl;
	else
		cout<<"\n\tGraph is Possible."<<endl;
	return 0;
}
