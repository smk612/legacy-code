#include <stdio.h>
#include <math.h>
#include "fact.h"
 void main()
 {
	int i,k;
	double s=0,n,x;
	printf("Enter the degree\n");
	scanf("%lf",&n);
	n=n*3.14/180;
	for(i=1,k=0;k<20;i=i+2,k++)
	{
	x=(double)pow(n,i)/fact(n);
	//printf("%lf\n",n);
	if(k%2==0)
	s=s+x;
	else
	s=s-x;
	}
	printf("The answer is %lf\n",s);
 }

