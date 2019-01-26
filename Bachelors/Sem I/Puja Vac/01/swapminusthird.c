#include <stdio.h>
void main()
{
	int a,b;
	printf("Enter a and b separated by space\n");
	scanf("%d %d",&a,&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("The swapped numbers are a = %d and b = %d\n",a,b);
}
