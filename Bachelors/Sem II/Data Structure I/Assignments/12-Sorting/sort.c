//C Program for Menu Driven Sorting
#include <stdio.h>
int modbubblesort(int *a,int n);//Fucntion that sorts the array elements using Modified Bubble Sort
int insertionsort(int *a,int n);//Fucntion that sorts the array elements using Insertion Sort
int display(int *a,int n);//Displays the array
int main()
{
	int i,n,ch;
	do
	{
		printf("\n\tEnter the number of elements::");
		scanf("%d",&n);
		int a[n];
		printf("\n\tEnter the elements::");
		for(i=0;i<n;)
		{
			scanf("%d",&a[i++]);
		}
		printf("\n\tMenu::\n\t1.Sort Using Bubble Sort.\n\t2.Sort Using Insertion Sort.\n\t3.Exit.\n\tEnter Choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: modbubblesort(a,n);
				printf("\n\tThe array after sorting is::\n");
				display(a,n);
				break;
			case 2: insertionsort(a,n);
				printf("\n\tThe array after sorting is::\n");
				display(a,n);
				break;
			case 3: printf("\n\tProgram Terminated.\n");
				break;
			default:printf("\n\tInvalid Choice. Enter Again.\n");
		}
	}
	while(ch!=3);
	return 0;
}
int modbubblesort(int *a,int n)
{
	int i,j,flag,tmp;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				flag=1;
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
		printf("\n\tThe array after pass %d::",i+1);
		display(a,n);
		if(flag==0)//Indicates that all the elements are in their correct position and that no swapping has been done
			return 1;
	}
	return 0;
}
int insertionsort(int *a,int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		for(j=i-1;(j>=0)&&(a[j]>key);j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=key;//inserts the key at proper position
		printf("\n\tThe array after pass %d::",i);
		display(a,n);
	}
	return 0;
}
int display(int *a,int n)
{
	int i;
	for(i=0;i<n;printf("\t%d",a[i++]));
	return 0;
}
