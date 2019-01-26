#include <stdio.h>
void main()
{
float a,b,c;
char ch='1';
while(ch!='0')
{
    printf("Enter 1st number \n");
    scanf("%f",&a);
    printf("Enter 2st number \n");
    scanf("%f",&b);
    printf("Enter operand or Enter 0 to quit\n");
    getchar();
    scanf("%c",&ch);
    switch(ch)
    {
    case '+':c=a+b;
	    printf("%f\n",c);
    break;
    case '-':c=a-b;
	    printf("%f\n",c);
    break;
    case '*':c=a*b;
	    printf("%f\n",c);
    break;
    case '/':if(b!=0)
		    {c=a/b;printf("%f\n",c);}
	    else
	    printf("Cannot Divide by Zero");
    break;
    default:printf("Invalid option\n");
}
}
}

