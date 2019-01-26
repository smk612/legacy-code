//C Program to Solve a System of equations by Gauss Elimination Method
#include <stdio.h>
#include <math.h>
int main()
{
	int n,i,j,k;
	printf("Enter the number of Equations and the number of variables::");
	scanf("%d",&n);
	printf("Enter the coefficients of the equations\n");
	double a[n][n+3],s;
	for(i=0;i<n;i++)
	{
		printf("Equation %d\n",i+1);
		for(j=0;j<=n;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
		printf("x%d\t",i);
	printf("b\tm\n");
	for(i=0;i<n-1;i++)
	{
		printf("Step %d\n",i+2);
		for(j=i+1;j<n;j++)
		{
			a[j][n+1]=-a[j][i]/a[i][i];
			for(k=0;k<=i;k++)
				printf("\t");
			for(k=i+1;k<=n;k++)
			{
				a[j][k]=a[j][k]+(a[j][n+1]*a[i][k]);
				printf("%.3lf\t",a[j][k]);
			}
			printf("%.3lf\n",a[j][n+1]);
		}	
	}
	printf("The Solutions are::\n");
	for(i=n-1;i>=0;i--)
	{
		s=0;
		for(j=i;j<=n;j++)
		{
			s=s+a[i][j]*a[j][n+2];
		}
		a[i][n+2]=(a[i][n]-s)/a[i][i];
		printf("x%d=%.3lf\n",i+1,a[i][n+2]);
	}
	return 0;
}
