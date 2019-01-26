#include<stdio.h>
#include<math.h>
main()
{
float a[10],sum=0,avg=0,q=0,sd=0;
long t=0,s=0;
int i;
printf("enter the elements of the array\n");
for(i=0;i<10;i++)
{
scanf("%f",&a[i]);
}
for(i=0;i<10;i++)
{
sum=sum+a[i];
}
avg=sum/10;
for(i=0;i<10;i++)
{
q=a[i]-avg;
t=q*q;
s=s+t;
}
sd=sqrt(s/10);
printf("the avg is %f\n",avg);
printf("the standard deviation is %f\n",sd);
}

