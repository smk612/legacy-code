#include <stdio.h>
int main()
{
	int n,i,j,m;
	double x,h,u,p,s;
	printf("Enter number of arguments:");
	scanf("%d",&n);
	m=n+1;
	double f[n][n+1];
	printf("Enter values of x\n");
	for(i=0;i<n;i++)
	{
		scanf("%lf",&f[i][0]);
		if(i==1)
		{
			h=f[1][0]-f[0][0];
		}
		if((i>1)&&(f[i][0]-f[i-1][0]!=h))
		{
			printf("%lf %lf Non-equispaced intervals. Program Terminated\n",h,f[i][0]-f[i-1][0]);
			return 1;
		}
	}
	printf("Enter corresponding values of y i.e f(x)\n");
	for(i=0;i<n;i++)
	{
		scanf("%lf",&f[i][1]);
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			f[j][i+1]=f[j+1][i]-f[j][i];
		}
		m--;
	}
	m=n+1;
	printf("The Backward Difference Table is:\nx\tf(x)\t▽f(x)");
	for(i=2;i<n;i++)
	{
		printf("\t▽^%df(x)",i);
	}
	printf("\n--------------------");
	for(i=2;i<=n;i++)
	{
		printf("-------");
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<m;j++)
		{
			printf("%.3lf\t",f[i][j]);
		}
		m--;
	}
	printf("\nEnter x for which you want to find the value of f(x):");
	scanf("%lf",&x);
	if(x<(f[0][0]+f[n-1][0])/2)
	{
		printf("Value of x is near the front of the table. Use Newton's Forward formula. Program Terminated\n");
		return 2;
	}
	u=(x-f[n-1][0])/h;
	s=f[n-1][1];
	p=u;
	m=n+1;
	for(i=n-2,j=2;i>=0;i--,j++)
	{
		s=s+(p*f[i][j]);
		p=p*(u+j-1)/j;
	}
	printf("The value of f(x) for given x is %.3lf\n",s);
	return 0;
}
