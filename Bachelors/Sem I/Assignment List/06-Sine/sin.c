/*C Program to find Sine of an Angle*/
#include <stdio.h>
#include <math.h>

/*Use user-defined function to find Factorial*/
double fact(int);
int main()
{
	int i;
	double deg,sine=0;
	
	/*Read the input*/
	printf("Enter the degree:");
	scanf("%lf",&deg);
	printf("The value of sin(%3.1lf) is: ",deg);
	
	/*Convert Degree to radian*/
	deg=3.142/180*deg;
	
	/*Run loop to find sum of 1st 20 terms*/
	for(i=0;i<20;i++)
	{
		if(i%2==0)
			sine=sine+(pow(deg,2*i+1)/fact(2*i+1));
		else
			sine=sine-(pow(deg,2*i+1)/fact(2*i+1));
	}
	printf("%6.4lf\n",sine);
	return 0;
}
double fact(int x)
{
	if(x==0)
		return 1;
	else 
		return(x*fact(x-1));
}
