//C Program to find the Soln of an Equation using Newton-Raphson's
#include <stdio.h>
#include <math.h>
double eq(double x,int d)
{
	if(!d)
		return (pow(x,3)-x-.1);
	else
		return (3*pow(x,2)-1);
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
	double x,e,h,y;
	printf("The equation we are solving is->	x^3-x-.1=0\n");
	printf("Enter value of x0::");
	scanf("%lf",&x);
	y=x;
	printf("You need the answer correct upto how many decimal places? ::");
	scanf("%lf",&e);
	e=error(e);
	printf("n\tx(n)\t\t\tf(x(n))\t\t\tf'(x(n))\t\th\t\t\tx(n+1)\n");
	do
	{
		x=y;
		h=-eq(x,0)/eq(x,1);
		y=x+h;
		printf("%d\t%lf\t\t%lf\t\t%lf\t\t%lf\t\t%lf\n",i++,x,eq(x,0),eq(x,1),h,y);
	}
	while(mod(x-y)>e);
	printf("The root is %lf\n",x);
	return 0;
}
