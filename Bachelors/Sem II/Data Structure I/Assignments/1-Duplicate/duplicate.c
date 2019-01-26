/* C Program to delete the Duplicate elements from an array. */
#include <stdio.h>
#include <stdlib.h>
int duplicate(int *arr,int n);
int display(int *arr,int n);
int main()
{
	int n,i;
	
	/*Read inputs from the user*/
	printf("\n\tEnter size of array:");
	scanf("%d",&n);
	printf("\n\tEnter the elements:");
	
	/*Allocate space for the array*/
	int *arr=(int*)malloc(n*sizeof(int));
	
	/*Check if allocation successful or not*/
	if(!arr)
	{
		printf("\n\tAllocation failed");
		return 1;
		
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n\tArray before removing duplicate elements:");
	display(arr,n);
	printf("\n\tArray after removing duplicate elements:");
	
	/*Call function to remove duplicate elements*/
	n=duplicate(arr,n);
	free(arr);
	return 0;
}

/*Function to remove duplicate elements*/
int duplicate(int *arr,int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;)
		{
			if(arr[j]==arr[i])
			{
				for(k=j;k<n-1;k++)
				{
					arr[k]=arr[k+1];
				}
				n--;
			}
			else
				j=j+1;
		}
	}
	display(arr,n);
	
	/*n is returned so that the size of the array is also updated in the main program*/
	return n;
}

/*Function to display array*/
int display(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n\t%d",arr[i]);
	}
	printf("\n");
	return 0;
}
