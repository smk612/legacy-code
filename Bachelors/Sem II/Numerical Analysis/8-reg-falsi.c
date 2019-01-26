//C Program to find the Soln of an Equation using Regular-Falsi Method
#include <stdio.h>
#include <math.h>
double eq(double x)
{
	return (pow(x,3)+2*x-2);
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
	double a,b,h=0.0,k,l,e;
	printf("The equation we are solving is->	x^3+2*x-2=0\n");
	printf("Enter value of a::");
	scanf("%lf",&a);
	printf("Enter value of b::");
	scanf("%lf",&b);
	printf("You need the answer correct upto how many decimal places? ::");
	scanf("%lf",&e);
	e=error(e);
	if((eq(a)>0&&eq(b)<0)||(eq(b)>0&&eq(a)<0))//Condition that proves that the result lies between a and b
	{
		printf("n\ta(n)\t\tb(n)\t\tf(a(n))\t\tf(b(n))\t\th(n)\t\tx(n+1)\t\tf(x(n+1))\n");
		do
		{
			l=h;
			h=(mod(eq(a))*(b-a))/(mod(eq(a))+mod(eq(b)));
			k=a+h;
			printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",i++,a,b,eq(a),eq(b),h,k,eq(k));
			if(eq(k)>0)
				b=k;
			else if(eq(k)<0)
				a=k;
			else 
				break;
		}
		while(mod(l-h)>e);
		printf("The root is %.3lf\n",k);
	}
	else
	{
		printf("The result doesn't lie between a and b. Program Terminated.\n");
	}
	return 0;
}
