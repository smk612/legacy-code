#include<stdio.h>
#include<math.h>
void main()
 {
 	int x,s,i,flag=0;
 	printf("Enter the value\n");
	scanf("%d",&x);
	for(i=1;i<=x/2;i++)
	{
	if(x==i*i)
	{
	flag=1;
	break;
	}
	}
	if(flag==1)
	printf("It is a Perfect Square\n");
	else
	printf("It is not a Perfect Square\n");
 }



