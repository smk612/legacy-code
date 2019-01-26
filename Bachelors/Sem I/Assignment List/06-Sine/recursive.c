/* Recursive function in C to return Factorial of a number */
#include "recursive.h"
double fact(int x)
{
	if(x==0)
		return 1;
	else 
		return(x*fact(x-1));
}
