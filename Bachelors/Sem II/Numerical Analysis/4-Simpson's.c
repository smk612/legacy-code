//C Program to implement Simpson's one-third formula for Numerical Integration
#include <stdio.h>
#include <math.h>
#define EQ (1/(sqrt(1+pow(x,2))))
int main()
{
	int i=0,n;
	double x,s=0,h,u,l;
	printf("The equation we are solving is->   y=1/(sqrt(1+x^2))\n");
	printf("\n\tEnter upper limit::");
	scanf("%lf",&u);
	printf("\n\tEnter lower limit::");
	scanf("%lf",&l);
	printf("\n\tEnter number of intervals::");
	scanf("%d",&n);
	h=(u-l)/n;
	x=l;
	double a[n+1];
	for(i=0;i<=n;i++)
	{
		a[i]=EQ;
		printf("\n\t%lf\t%lf",x,a[i]);
		x=x+h;
		if((i==0)||(i==n))
		{
			s=s+a[i];
		}
		else
		{
			if(i%2)
			{
				s=s+(4*a[i]);
			}
			else
			{
				s=s+(2*a[i]);
			}
		}
	}
	s=s*h/3;
	if(n%2==0)
		printf("\n\t Value by Simpson's one-third rule is %lf\n",s);
	else
		printf("\n\tNumber of intervals odd.");
	return 0;
}
