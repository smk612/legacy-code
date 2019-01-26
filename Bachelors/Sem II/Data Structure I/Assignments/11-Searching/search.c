//C Program for Menu Driven Searching
#include <stdio.h>
int linsearch(int * a,int n,int key);//Function that searches using linear search method
int binsearchrec(int *a,int lb,int ub,int item);// Recursive Function that searches for given item using binary search
int interpolationsearch(int *a,int lb,int ub,int item);//Function that searches for given item using interpolation search
int main()
{
	int n,i,key,ch;
	printf("\n\tEnter the number of elements::");
	scanf("%d",&n);
	int a[n+1];
	printf("\n\tEnter the elements::");
	for(i=0;i<n;)
	{
		scanf("%d",&a[i++]);
	}
	do
	{
		printf("\n\tEnter item to be searched::");
		scanf("%d",&key);
		printf("\n\tMenu::\n\t1.Search using Linear Search.\n\t2.Search using Binary Search.\n\t3.Search using Interpolation Search.\n\t4.Exit.\n\tThe Array must be in ascending order for using Binary and Interpolation Searches.\n\tEnter Choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:i=linsearch(a,n,key);
				break;
			case 2: i=binsearchrec(a,0,n-1,key);
				break;
			case 3: i=interpolationsearch(a,0,n-1,key);
				break;
			case 4: printf("\n\tProgram Terminated.\n");
				return 1;
				break;
			default:printf("\n\tInvalid Choice. Enter Again.\n");
		}
		if(i==-1)
			printf("\n\tThe item is not found\n");
		else
			printf("\n\tThe item is found at index %d\n",i);
	}
	while(ch!=4);
	return 0;
}
int linsearch(int * a,int n,int key)
{
	int i=0;
	a[n+1]=key;
	while(a[i]!=key)
		i=i+1;
	if(i<n)
		return i;
	else
		return -1;
}
int binsearchrec(int *a,int lb,int ub,int item)
{
	if(lb>ub)
                return -1;
        else
        {
        	int mid=(lb+ub)/2;
        	if(item==a[mid])
        		return mid;
        	else if(item<a[mid])
        		return binsearchrec(a,lb,mid-1,item);
        	else
        		return binsearchrec(a,mid+1,ub,item);
        }
}
int interpolationsearch(int *a,int lb,int ub,int item)
{
	int mid=0;
	do
	{
		if(mid==lb+((ub-lb)*((item-a[lb]))/(a[ub]-a[lb])))
			break;
		mid=lb+((ub-lb)*((item-a[lb]))/(a[ub]-a[lb]));
		if(item<a[mid])
			ub=mid-1;
		else
			lb=mid+1;
	}
	while((a[mid]!=item)&&(lb<=ub));
	if(item==a[mid])
		return mid;
	else
		return -1;
}
