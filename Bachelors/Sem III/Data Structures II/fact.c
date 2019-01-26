/*C Program to find factorial of numbers using array
	Application of Array
*/
#include<stdio.h>
int main()
{
	int n,t,i,d,x=0;
	int a[1000];
	printf("\n\tEnter number::");
	scanf("%d",&n);
	for(i=0;i<1000;i++)
		a[i]=-1;
	i--;
	t=n;
	while(t>0)
	{
		a[i--]=t%10;
		t=t/10;
	}
	n--;
	while(n!=1)
	{
		i=999;
		while(a[i]!=-1)
		{
			d=x+(n*a[i]);
			a[i]=d%10;
			x=d/10;
			i--;
		}
		if((a[i]==-1)&&(x!=0))
		{
			while(x>0)
			{
				a[i--]=x%10;
				x=x/10;
			}
		}
		n--;
	}
	i++;
	while(i!=1000)
		printf("%d",a[i++]);
	return 1;
}
