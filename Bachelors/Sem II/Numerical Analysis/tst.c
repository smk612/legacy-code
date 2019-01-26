#include <stdio.h>
#include <math.h>
#define EQ (a*a*a-a-.1)
#define EQD (3*a*a-1)
double mod(double x)
{
	if(x<0)
		return -x;
	else
		return x;
}
double error(int a)
{
	return 5*pow(10,-a);
}
int main()
{
	int err;
	double a=1,f,h=a,x;
	scanf("%d",&err);
	printf("%lf",error(err));
	while(mod(h)>.000005)
	{
	f=EQD;
	h=-EQ/EQD;
	x=a+h;
	printf("\n\tx(n)=%lf\tf'(x)=%lf\th=%lf\tx(n+1)=%lf",a,f,h,x);
	a=x;
	}
	printf("\n\tThe root is %.6lf\n",a);
	return 0;
}
