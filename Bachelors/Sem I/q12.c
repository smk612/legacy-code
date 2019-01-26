#include<stdio.h>
main(){	
int a,b,c;c=0;
	printf("enter the no.");
	scanf("%d",&a);
	for(b=1;b<=a;b++){
		if(a%b==0)
		c++;
	}
if(c==2)
printf("the no is prime no.\n");
else
printf("the no is not a prime no.\n");
}
	
