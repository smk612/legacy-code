/* C Program to Reverse the elements of an array. */
#include <stdio.h>
#include <stdlib.h>
int reverse(int *arr,int n);
int display(int *arr,int n);
int main()
{
	int n,i;
	
	/*Read inputs from the user*/
	printf("\n\tEnter size of array:");
	scanf("%d",&n);
	printf("\n\tEnter the elements:");
	
	/*allocate space for the array*/
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
	printf("\n\tArray before Reversing:");
	display(arr,n);
	printf("\n\tArray after Reversing:");
	
	/*Call function to reverse the array*/
	reverse(arr,n);
	free(arr);
	return 0;
}

/*Function to reverse the array*/
int reverse(int *arr,int n)
{
	int i,temp;
	for(i=0;i<n/2;i++)
	{
		temp=arr[i];
		arr[i]=arr[n-i-1];
		arr[n-i-1]=temp;
	}
	display(arr,n);
	return 0;
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
