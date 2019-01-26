#include <stdio.h>
#include <stdlib.h>
display(int *mat,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",mat[i]);
	}
	printf("\n");
}
int duplicate(int *a,int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;)
		{
			if(a[j]==a[i])
			{
				for(k=j;k<n-1;k++)
				{
					a[k]=a[k+1];
				}
				n--;
			}
			else
				j=j+1;
		}
	}
	display(a,n);
	return n;
}
int reverse(int *a,int n)
{
	int i,temp;
	for(i=0;i<n/2;i++)
	{
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}
	display(a,n);
	return 0;
}
int main()
{
	int n,i,ch;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter the elements\n");
	int *a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	do
	{
	printf("Enter 1 to remove Duplicate elements,\n 2 to reverse the array \nor 3 to Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:n=duplicate(a,n);
			break;
		case 2:reverse(a,n);
			break;
		default:printf("EndOfProgram\n");
			free(a);
			ch=0;
	}
	}
	while(ch!=0);
	return 0;
}
