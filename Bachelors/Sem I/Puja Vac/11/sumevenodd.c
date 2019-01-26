#include <stdio.h>
void main()
{
   int i,so=0,se=0,n;
   printf("Enter number of elements\n");
   scanf("%d",&n);
   int a[n];
   printf("Enter the numbers separated by space\n");
   for(i=0;i<n;i++)
   {
   	scanf("%d",&a[i]);
   	if(a[i]%2==0)
   	se=se+a[i];
   	else
   	so=so+a[i];
   }
   printf("The sum of odd numbers is %d and of even numbers is %d\n",so,se);
   }

