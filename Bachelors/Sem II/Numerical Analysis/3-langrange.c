//C Program to implement Langrange's Interpolation Formula
#include <stdio.h>
int main()
{	
	int n,i,j;
	printf("Enter number of arguments::");
	scanf("%d",&n);
	double f[n][n+4],x,d,w=1,s=0;
	printf("Enter values of x\n");
	for(i=0;i<n;i++)
	{
		scanf("%lf",&f[i][0]);
	}
	printf("Enter corresponding values of y\n");
	for(i=0;i<n;i++)
	{
		scanf("%lf",&f[i][n+2]);
	}
	printf("Enter the value of x for which you want to find the result::");
	scanf("%lf",&x);
	for(i=0;i<n;i++)
	{
		d=1;
		for(j=1;j<n+1;j++)
		{
			if(j==i+1)
			{
				f[i][j]=x-f[j-1][0];
				w=w*f[i][j];
			}
			else
			{
				f[i][j]=f[i][0]-f[j-1][0];
			}
			d=d*f[i][j];
		}
		f[i][j]=d;
		f[i][j+2]=f[i][j+1]/d;
		s=s+f[i][j+2];
	}
	printf("The Computational Table is::\nx");
	for(i=0;i<n-1;i++)
	{
		printf("\t\t");
	}
	printf("Row Product=\t\tD\t\ty\t\ty/D\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+4;j++)
		{
			printf("%lf\t",f[i][j]);
		}
		printf("\n");
	}
	s=w*s;
	printf("The value of y by langrange's formula is:%lf\n",s);
	return 0;
}
