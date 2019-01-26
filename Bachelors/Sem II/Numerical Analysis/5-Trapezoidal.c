//C Program to implement Trapezoidal formula for Numerical Integration
#include <stdio.h>
#include <math.h>
#define EQ (1/(sqrt(1+pow(x,2))))
int main()
{
	int i=0,n;
	double x,t=0,h,u,l;
	printf("The equation we are solving is->	y=1/(sqrt(1+x^2))\n");
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
			t=t+a[i];
		}
		else
		{
			t=t+(2*a[i]);
		}
	}
	t=t*h/2;
	printf("\n\t Value by Trapezoidal rule is %lf ",t);
	return 0;
}
