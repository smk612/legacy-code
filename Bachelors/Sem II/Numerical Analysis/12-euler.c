//C Program to Find Solution of Ordinary Differential Equation of 1st Order by Euler's Method
#include <stdio.h>
#include <math.h>
#define f(x,y) (pow(x,3)+y)
int main()
{
	int i;
	double x,y,h,s;
	printf("f(x,y)=x^3+y\nEnter Value of x::");
	scanf("%lf",&x);
	printf("Enter Value of y for x=%lf::",x);
	scanf("%lf",&y);
	printf("Enter Step length h::");
	scanf("%lf",&h);
	printf("Enter value of x for which y is to be computed::");
	scanf("%lf",&s);
	for(i=1;x<s;i++)
	{
		y=y+(h*f(x,y));
		x=x+h;
		printf("%d\ty(%.2lf)=%.8lf\n",i,x,y);
	}
	return 0;
}
