//C Program to find the Soln of an Equation using Bisection Method
#include <stdio.h>
#include <math.h>
double eq(double x)
{
	return (pow(x,3)-9*x+1);
}
double mod(double x)
{
	if(x<0)
		return -x;
	else
		return x;
}
double error(int a)
{
	return 5*pow(10,-a-1);
}
int main()
{
	int i=0;
	double a,b,x,e,f;
	printf("The equation we are solving is->	x^3-9*x+1=0\n");
	printf("Enter value of a::");
	scanf("%lf",&a);
	printf("Enter value of b::");
	scanf("%lf",&b);
	x=(a+b)/2;
	printf("You need the answer correct upto how many decimal places? ::");
	scanf("%lf",&e);
	e=error(e);
	if((eq(a)>0&&eq(b)<0)||(eq(b)>0&&eq(a)<0))//Condition that proves that the result lies between a and b
	{
		printf("n\ta(n)\t\t\tb(n)\t\t\tx(n+1)\t\t\tf(x(n+1))\n");
		while((mod(a-b)>e)||(mod(b-x)>e)||(mod(x-a)>e))
		{
			x=(a+b)/2;
			f=eq(x);
			printf("%d\t%lf\t\t%lf\t\t%lf\t\t%lf\n",i++,a,b,x,f);
			if(f>0)
				b=x;
			else if(f<0)
				a=x;
			else 
				break;
		}
		printf("The root is %lf\n",x);
	}
	else
	{
		printf("The result doesn't lie between a and b. Program Terminated.\n");
	}
	return 0;
}
