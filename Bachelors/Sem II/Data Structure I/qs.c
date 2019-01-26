#include <stdio.h>
int display(int *a,int n);
int partition(int *x,int lb,int ub);
void quicksort(int *a,int lb,int ub);
int main()
{
	int a[]={5,4,3,2,1,0};
	quicksort(a,0,5);
	display(a,5);
	return 0;
}
int partition(int *x,int lb,int ub)
{
	int tmp;
	int a=x[lb];
	int up=ub;
	int down=lb;
	while(down<up)
	{
		while(x[down]<=a&&down<up)
			down=down+1;
		while(x[up]>a)
			up=up-1;
		if(down<up)
		{
			tmp=x[down];
			x[down]=x[up];
			x[up]=tmp;
		}
	}
	x[lb]=x[up];
	x[up]=a;
	return up;
}
void quicksort(int *a,int lb,int ub)
{
	if(lb>=ub)
	{
		return;
	}
	else
	{
		int j=partition(a,lb,ub);
		quicksort(a,lb,j-1);
		display(a,5);
		printf("\nOLE");
		quicksort(a,j+1,ub);
		display(a,5);
	}
}
int display(int *a,int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;printf("\t%d",a[i++]));
	return 0;
}
