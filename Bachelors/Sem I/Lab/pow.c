#include <stdio.h>
void main()
{
	int x,y,i;
	unsigned long s=1;
	printf("Enter x and y separated by space\n");
	scanf("%d %d",&x,&y);
	for(i=0;i<y;i++)
	{
	s=s*x;
	}
	printf("The power of x raised to y is %ld\n",s);
}
