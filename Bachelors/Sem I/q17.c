#include<stdio.h>
main()
{
int a,b,c,i;
a=b=1;c=a+b;
printf("the fibonaci series are\n%d\n%d\n",a,b);
for(i=2;i<31;i++){
	printf("%d\n",c);
a=b;b=c;c=a+b;}
}
