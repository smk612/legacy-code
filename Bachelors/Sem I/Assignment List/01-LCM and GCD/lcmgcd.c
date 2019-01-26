/* C Program to Find Lowest Common Multiple and Greatest Common Divisor. */
#include <stdio.h>
#include <stdlib.h>
int main()
{	
	int i,num1,num2,gcd,lcm,flag=0;
	
	/*Read inputs from the user*/
	printf("Enter the first number\n");
	scanf("%d",&num1);
	printf("Enter the second number\n");
	scanf("%d",&num2);	
	
	/*Checking if one of the numbers is zero*/
	if(num1==0||num2==0) 
	{
		printf("The LCM of the numbers is: 0 and the GCD is: %d\n",(num1==0)?num2:num1);
		exit(0);
	}
	for(i=1;i<=(num1*num2);i++) 
	{
		/*Condition for GCD*/
		if((num1%i==0)&&(num2%i==0)) 
		{
			gcd=i;
		}
		
		/*Condition for LCM and also checking that only the LOWEST common multiple is taken*/
		if((flag==0)&&(i%num1==0)&&(i%num2==0)) 
		{
			lcm=i;
			flag=1;
		}
	}
	printf("The LCM of the numbers is: %d and the GCD is: %d\n",lcm,gcd);
	return 0;
}
