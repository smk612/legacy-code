/* Main program in C to find out Factorial */
#include <stdio.h>
#include "recursive.h"
int main()
{
	int n;
	double x;
	
	/*Read the input*/
	printf("Enter a number to find its factorial\n");
	scanf("%d",&n);
	
	/*Check to see if input is negative or not*/
	if(n>=0)
	{
		x=fact(n);
		printf("The factorial is %g\n",x);
	}
	else
		printf("Factorial of a negative number doesn't exist\n");
 	return 0;
}
