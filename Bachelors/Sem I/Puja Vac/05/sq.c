#include <stdio.h>
#define square(x)  (x*x)
 void main()
 {
	int x,s;
	printf("Enter the value\n");
	scanf("%d",&x);
	s=square(x);
	printf("Its square is  %d\n",s);
 }
