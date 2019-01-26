//C Program to Find Solution of Ordinary Differential Equation of 1st Order by Runge-Kutta Method of Order 4
#include <stdio.h>
#include <math.h>
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
double f(double x,double y)
{
	return (x-y);
}
int main()
{
	double x0,x,y0,h,k,k1,k2,k3,k4;
	printf("f(x,y)=x-y\nEnter Value of x::");
	scanf("%lf",&x0);
	printf("Enter Value of y for x=%4.2lf::",x);
	scanf("%lf",&y0);
	printf("Enter Step length h::");
	scanf("%lf",&h);
	printf("Enter value of x for which y is to be computed::");
	scanf("%lf",&x);
	printf("y(%4.2lf)=%.4lf\n",x0,y0);
	while(x0<x)
	{
		k1=h*f(x0,y0);
		k2=h*f(x0+(h/2),y0+(k1/2));
		k3=h*f(x0+(h/2),y0+(k2/2));
		k4=h*f(x0+h,y0+k3);
		k=(k1+2*(k2+k3)+k4)/6;
		y0=y0+k;
		x0=x0+h;
		printf("y(%4.2lf)=%.4lf\n",x0,y0);
	}
	return 0;
}
