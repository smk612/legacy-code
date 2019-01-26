//C Program to Find Solution of Ordinary Differential Equation of 1st Order by Euler's Modified Method
#include <stdio.h>
#include <math.h>
#define f(x,y) (x+y)
double error(int a)
{
	return 5*pow(10,-a-1);
}
double mod(double x)
{
	if(x<0)
		return -x;
	else
		return x;
}
int main()
{
	double x0,x,h,e,e1,y0,y1,y2,k0,k1;
	printf("f(x,y)=x+y\nEnter Value of x::");
	scanf("%lf",&x0);
	printf("Enter Value of y for x=%4.2lf::",x);
	scanf("%lf",&y0);
	printf("Enter Step length h::");
	scanf("%lf",&h);
	printf("Enter value of x for which y is to be computed::");
	scanf("%lf",&x);
	printf("You need the answer correct upto how many decimal places? ::");
	scanf("%lf",&e);
	e=error(e);
	printf("y(%4.2lf)=%.4lf\n",x0,y0);
	while(x0<x)
	{
		k0=f(x0,y0);
		y1=y0+h*k0;
		e1=1;
		while(e1>e)
		{
			k1=f(x0+h,y1);
			y2=y0+h*(k0+k1)/2;
			e1=mod(y2-y1);
			y1=y2;
		}
		y0=y1;
		x0=x0+h;
		printf("y(%4.2lf)=%.4lf\n",x0,y0);
	}
	return 0;
}
