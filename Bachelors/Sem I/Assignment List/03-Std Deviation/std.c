/* C Program to find Max, Min, Mean and Standard Deviation of an array of 10 numbers*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ARRSIZE (10)
int main()
{
	int i;
	float a[ARRSIZE],max,min,mean,std,sum=0;
	
	/*Read the inputs*/
	printf("Enter the numbers:\n");
	for(i=0;i<ARRSIZE;i++)
	{
		scanf("%f",&a[i]);
		sum=sum+a[i];
	}
	max=min=a[0];
	mean=sum/ARRSIZE;
	sum=0;
	
	/*Calculating Standard Deviation and finding Maximum and Minimum*/
	for(i=0;i<ARRSIZE;i++)
	{
		sum=sum+pow(a[i]-mean,2);
		if(a[i]>max)
		{
			max=a[i];
		}
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	std=sqrt(sum/ARRSIZE);
	
	/*Printing the Results*/
	printf("The Maximum is :%8.2f\nThe Minimum is :%8.2f\nThe Mean is :%8.2f\nThe Standard Deviation is :%8.2f\n",max,min,mean,std);
	return 0;
}
