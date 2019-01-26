/*C Program to Sort an Array*/
#include <stdio.h>
#define ARRSIZE 10
int selection_sort(int a[]); 
int bubble_sort(int a[]);
int main()
{
	int i,a[ARRSIZE]={0},b[ARRSIZE]={0},ch=0;
	
	/*Read Input*/
	printf("Enter 10 elements of the array\n");
	for(i=0;i<ARRSIZE;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	
	/*Display Menu to the user*/
	do
	{
		printf("Menu:\n1)Display Original Array\n2)Perform Selection Sort\n3)Perform Bubble Sort\n4)Exit\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
			case 1: printf("Original Array is:\n");
					for(i=0;i<ARRSIZE;i++)
					{
						printf("%d\t",a[i]);
					}
					printf("\n");
					break;
			case 2: selection_sort(b);
					break;
			case 3: bubble_sort(b);
					break;
			case 4: return 1;
					break;
			default:printf("Invalid Choice\n");
		}
	}
	while(ch!=4);
	return 0;
}

/*Function to perform Selection Sort*/
int selection_sort(int a[])
{
	int i,j,min,tmp,pos=0;
	for(i=0;i<ARRSIZE;i++)
	{
		
		/*Initialise min to the subscript of the current element*/
		min=a[i];
		pos=i;
		for(j=i+1;j<ARRSIZE;j++)
		{
			
			/*Find smallest element between the positions i and ARRSIZE*/
			if(a[j]<min)
			{
				min=a[j];
				pos=j;
			}
		}
		
		/*Swap smallest element with one in position i*/
		tmp=a[pos];
		a[pos]=a[i];
		a[i]=tmp;
	}
	printf("Array after Selection sort is:\n");
	for(i=0;i<ARRSIZE;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}

/*Function to perform Bubble Sort*/
int bubble_sort(int a[])
{
	
	/*Set flag to 1 to begin initial pass*/
	int i,flag=1,tmp;
	while(flag)
	{
		
		/*Set flag to 0 awaiting a possible swap*/
		flag=0;
		for(i=0;i<ARRSIZE-1;i++)
		{
			if(a[i]>a[i+1])
			{
				
				/*Swap elements and then set flag to 1 to indicate that a swap occured*/
				tmp=a[i];
				a[i]=a[i+1];
				a[i+1]=tmp;
				flag=1;
			}
		}
	}
	printf("Array after Bubble sort is:\n");
	for(i=0;i<ARRSIZE;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}
