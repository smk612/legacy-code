#include <stdio.h>
#include "fact_1.h"
int n;
void main()
 {
	double x;
	printf("Enter a number to find its factorial\n");
	scanf("%d",&n);
	if(n>0)
	{
	x=fact();
	printf("The factorial is %g\n",x);
	}
	else
	printf("Factorial of a negative number doesn't exist\n");
 }

