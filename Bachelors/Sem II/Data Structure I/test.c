#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
struct Sparse
{
	int i,j,val;
};
int checkrc(int a,int b);//checks if valid row and column number
int checksparse(int a,int b);//checks if number of elements acceptable for sparse matrix
int checkzero(int x);//checks for zero, returns 1 if zero else returns 0
int check(int a,int b);//compares to numbers, returns -1 if a<b,0 if a==b, 1 if a>b
int structip(struct Sparse * a,int r,int c,int val);// inputs matrix
int structstore(struct Sparse * d,int z,int i,int j,int val);//stores in the structure
int structadd(struct Sparse * a,struct Sparse * b,struct Sparse * d,int r,int c);//adds the content of two structures
int structdisp(struct Sparse * a,int x);//displays the structure array
int main()
{
	int r,c,x,y;
	printf("Enter size ::");
	scanf("%d %d",&r,&c);
	checkrc(r,c);
	y=.25*r*c;
	printf("Enter number of non-zero elements in 1st Matrix::");
	scanf("%d",&x);
	checksparse(x,y);
	struct Sparse a[x+1];
	structip(a,r,c,x);
	printf("Enter number of non-zero elements in 2nd Matrix::");
	scanf("%d",&x);
	checksparse(x,y);
	struct Sparse b[x+1],d[x+a[0].val];
	structip(b,r,c,x);
	structadd(a,b,d,r,c);
	printf("The First Matrix is::\n");
	structdisp(a,-1);
	printf("The Second Matrix is::\n");
	structdisp(b,-2);
	printf("The Final Matrix is::\n");
	structdisp(d,0);
	return 0;
}
int checkrc(int a,int b)
{
	if(a<=0||b<=0)
	{
		printf("Row or Column Number cant be accepted.\nProgram Terminated.\n");
		exit (1);
	}
	else
		return 1;
}
int checksparse(int a,int b)
{
	if(a>b)
	{
		printf("No of non-zero elements is not suitable for sparse matrix.\nProgram Terminated.\n");
		exit (2);
	}
	else
		return 2;
}
int checkzero(int x)
{
	if(x==0)
		return 1;
	return 0;
}
int check(int a,int b)
{
	if(a<b)
		return -1;
	else if(a==b)
		return 0;
	else
		return 1;
}
int structip(struct Sparse * a,int r,int c,int val)
{
	int i,x;
	a[0].i=r;
	a[0].j=c;
	a[0].val=val;
	printf("Enter the elements of the matrix along with position::\n\ti\tj\tval\n----------------------------------------------\n");
	for(i=1;i<val+1;i++)
	{
		scanf("%d %d %d",&a[i].i,&a[i].j,&x);
		if(checkzero(x))
		{
			i--;
			continue;
		}
		a[i].val=x;
		checkrc(a[i].i,a[i].j);
		if((a[i].i>a[0].i)||(a[i].j>a[0].j))
		{
			printf("Entered value exceeds boundary.\nProgram Terminated.\n");
			exit(4);
		}
	}
	return 3;
}
int structstore(struct Sparse * d,int z,int i,int j,int val)
{
	d[z].i=i;
	d[z].j=j;
	d[z].val=val;
	d[0].val++;
	return 0;
}
int structadd(struct Sparse * a,struct Sparse * b,struct Sparse * d,int r,int c)
{
	int x,y,z;
	d[0].i=r;
	d[0].j=c;
	d[0].val=0;
	for(x=1,y=1,z=1;(x<=a[0].val)&&(y<=b[0].val);)
	{
		if(check(a[x].i,b[y].i)==-1)
		{
			structstore(d,z,a[x].i,a[x].j,a[x].val);
			x++;
			z++;//structdisp(d,1);
		}
		else if(check(a[x].i,b[y].i)==1)
		{
			structstore(d,z,b[y].i,b[y].j,b[y].val);
			y++;
			z++;//structdisp(d,2);
		}
		else
		{
				if(check(a[x].j,b[y].j)==-1)
			{
				structstore(d,z,a[x].i,a[x].j,a[x].val);
				x++;
				z++;//structdisp(d,3);
			}
			else if(check(a[x].j,b[y].j)==1)
			{
				structstore(d,z,b[y].i,b[y].j,b[y].val);
				y++;
				z++;//structdisp(d,4);
			}
			else
			{
				if(!checkzero(a[x].val+b[y].val))
				{
					structstore(d,z,b[y].i,b[y].j,a[x].val+b[y].val);
					z++;
				}
				x++;
				y++;//structdisp(d,5);
			}
		}
	}
	if(x>a[0].val)
	{
		for(;y<=b[0].val;)
		{
			structstore(d,z,b[y].i,b[y].j,b[y].val);
			y++;
			z++;//structdisp(d,6);
		}
	}
	else if(y>b[0].val)
	{
		for(;x<=a[0].val;)
		{
			structstore(d,z,a[x].i,a[x].j,a[x].val);
			x++;
			z++;//structdisp(d,7);
		}
	}
	return 4;
}
int structdisp(struct Sparse * a,int x)
{
	int i;
	printf("\n%d\ti\tj\tval\n----------------------------------------------\n",x);
	for(i=0;i<=a[0].val;i++)
	{
		printf("\n\t%d\t%d\t%d\n",a[i].i,a[i].j,a[i].val);
	}
	return 0;
}
