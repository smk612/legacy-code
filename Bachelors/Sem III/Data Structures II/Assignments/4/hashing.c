#include <stdio.h>
#define ARRSIZE 100
#define DIG 2//number of digits of the index
int methdiv(int a[],int n);//function to implement the division method, works on d
int methmidsq(int a[],int n);//function to implement the mid-square method, works on m
int methfold(int a[],int n);//function to implement the folding method, works on f
int methuser(int u[],int x);//user defined hash function
int place(int a[],int index,int n);
int collres(int a[],int index);//sends the array and the index where it is colliding, returns an empty index or -1 if the array is full. Searches by linear probing.
int upow(int x,int y);
int main()
{
	int i,n=1,d[ARRSIZE]={0},m[ARRSIZE]={0},f[ARRSIZE]={0},u[ARRSIZE]={0};
	int cd=0,cm=0,cf=0,cu=0,count=0;
	printf("\n\tONLY POSITIVE NON-ZERO NUMBERS. Entering any negative number will stop taking inputs.\n");
	printf("\tEnter the numbers::");
	while((n>0)&&(count<ARRSIZE))
	{
		
		scanf("%d",&n);
		if(n<=0)
			break;
		cd+=methdiv(d,n);
		cm+=methmidsq(m,n);
		cf+=methfold(f,n);
		cu+=methuser(u,n),
		count++;
	}
	printf("\n\tThe final individual hash tables are::\n\tIndex\tDivision\tMid-Square\tFolding\t\tUser");
	for(i=0;i<ARRSIZE;i++)
	{
		printf("\n\t%d|\t%d\t\t%d\t\t%d\t\t%d",i,d[i],m[i],f[i],u[i]);
	}
	printf("\nCollisions:\t%d\t\t%d\t\t%d\t\t%d\n",cd,cm,cf,cu);
	return 0;
}
int methdiv(int d[],int x)
{
	int add=x%ARRSIZE;
	return(place(d,add,x));
}
int methmidsq(int m[],int x)
{
	int i=0;
	unsigned long int t;
	t=x*x;
	while(t!=0)
	{
		t=t/10;
		i++;
	}
	t=x*x;
	i=i-DIG;
	i=i/DIG;
	t=t/upow(10,i);
	t=t%upow(10,DIG);
	return(place(m,(int)t,x));
}
int methfold(int f[],int x)
{
	int t=x,s=0;
	while(t!=0)
	{
		s=s+(t%upow(10,DIG));
		t=t/upow(10,DIG);
	}
	s=s%upow(10,DIG);
	return(place(f,s,x));
}
int methuser(int u[],int x)
{
	int t=x,s=0;
	while(t!=0)
	{
		s=s+(t%97);//replace 97 by the greatest prime before ARRSIZE
		t=t/97;
	}
	s=s%upow(10,DIG);
	return(place(u,s,x));
}
int place(int a[],int add,int x)
{
	if(a[add]==0)
	{
		a[add]=x;
		return 0;
	}
	else
	{
		add=collres(a,add);
		if(add!=-1)
			a[add]=x;
		else
			printf("\n\tHash Table is full.");
		return 1;
	}
}
int collres(int a[],int index)
{
	int i,j;
	for(i=index,j=index;(i>=0)||(j<ARRSIZE);i--,j++)
	{
		if(i>=0 && a[i]==0)
			return i;
		if(j<ARRSIZE && a[j]==0)
			return j;
	}
	return -1;
}
int upow(int x,int y)
{
	int i,s=1;
	for(i=0;i<y;i++)
	{
	s=s*x;
	}
	return s;
}
