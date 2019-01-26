#include <stdio.h>
void main()
{
   int n,i,p=0,r;
   printf("Enter a number\n");
   scanf("%d",&n);
   for(i=n;i>0;i=i/10)
   {
   	r=i%10;
   	p=(p*10)+r;
   }
   if(p==n)
   printf("Palindrome\n");
   else
   printf("Not palindrome\n");
}

