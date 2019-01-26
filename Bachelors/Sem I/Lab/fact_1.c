#include "fact_1.h"
extern int n;
 double fact()
 {
 	if(n==0)
	return 1;
	else 
	{
	n=n-1;
	return((n+1)*fact());
	}
 }

