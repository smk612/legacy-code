#include <stdio.h>
#include <math.h>
//#define pi 1/sqrt(2*M_PI)
#define EQ (1/(sqrt(1+pow(x,2))))
//#define EQ (pi*(exp(-x*x/2)))
main()
{
	int i=0,n;
	double x,t=0,s=0,h,u,l;
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
			s=s+a[i];
		}
		else
		{
			t=t+(2*a[i]);
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
	t=t*h/2;
	s=s*h/3;
	printf("\n\t Value by Trapezoidal rule is %lf ",t);
	if(n%2==0)
		printf("\n\t Value by Simpson's one-third rule is %lf\n",s);
	else
		printf("\n\tNumber of intervals odd.");
	return;
}
