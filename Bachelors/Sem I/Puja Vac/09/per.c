#include<stdio.h>
void main()
{
	float p;
	printf("Enter the percentage of the student\n");
	scanf("%f",&p);
	if(p>=70)
	{
	printf("Distinction\n");
	}
	else if(p>=60 && p<70)
	{
	printf("First Class\n");
	}
	else if(p>=50 && p<60)
	{
	printf("Second Class\n");
	}
	else if(p>=40 && p<50)
	{
	printf("Pass Class\n");
	}
	else
	{
	printf("Fail\n");
	}
	}
