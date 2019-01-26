//C Program to Solve a System of Equations by Gauss-Seidel Method
#include <stdio.h>
#include <math.h>
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
	int n,i,j,k=0,pos;
	printf("Enter the number of Equations and the number of variables::");
	scanf("%d",&n);
	printf("Enter the coefficients of the equations\n");
	double a[n][n+1],x[n],e,c,f;
	for(i=0;i<n;i++)
	{
		printf("Equation %d\n",i+1);
		x[i]=0;
		for(j=0;j<=n;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	printf("You need the answer correct upto how many decimal places? ::");
	scanf("%lf",&e);
	e=error(e);
	for(i=0;i<n;)
	{
		c=0;
		for(j=0;j<n;j++)
		{
			if(i!=j)
				c=c+mod(a[i][j]);
		}
		if(mod(a[i][i])>c)
			i=i+1;
		else
		{
			f=mod(a[i][0]);
			for(j=0;j<n;j++)
				if(mod(a[i][j])>f)
				{
					f=mod(a[i][j]);
					pos=j;
				}
			for(j=0;j<=n;j++)
			{
				f=a[i][j];
				a[i][j]=a[pos][j];
				a[pos][j]=f;
			}
		}
	}
	printf("The rearranged eqns are::");
	for(i=0;i<n;i++)
	{
		printf("\nEquation %d\n",i+1);
		for(j=0;j<=n;j++)
		{
			printf("%lf\t",a[i][j]);
		}
	}
	printf("\nk\t");
	for(i=0;i<n;i++)
		printf("x%d\t\t",i+1);
	printf("\n%d\t",k++);
	for(i=0;i<n;i++)
	{
		printf("%lf\t",x[i]);
	}
	do
	{
		c=0;
		for(i=0;i<n;i++)
		{
			f=x[i];
			x[i]=0;
			for(j=0;j<n;j++)
			{
				if(i!=j)
					x[i]=x[i]-(x[j]*a[i][j]/a[i][i]);
				else
					x[i]=x[i]+(a[i][n]/a[i][i]);
			}
			if(mod(x[i]-f)<e)
				c++;
		}
		printf("\n%d\t",k++);
		for(i=0;i<n;i++)
		{
			printf("%lf\t",x[i]);
		}
	}
	while(c!=n);
	printf("\nThe Solutions are::\n");
	for(i=0;i<n;i++)
		printf("x%d=%.2lf\n",i+1,x[i]);
	return 0;
}
