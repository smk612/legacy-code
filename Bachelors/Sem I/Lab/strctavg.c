#include <stdio.h>
struct student
{
	char name[50];
	int mark[4];
	char grade;
};
void main()
{
	int i,j,n;
	float sum[4]={0.0,0.0,0.0,0.0};
	printf("Enter number of students\n");
	scanf("%d",&n);
	struct student e[n];
	printf("Enter the names of the students\n");
	for(i=0;i<n;i++)
	{
	scanf("%s",&e[i].name);
	}
	printf("Enter the marks of the students\n");
	for(i=0;i<n;i++)
	{
	printf("Enter marks for %s",e[i].name);
		for(j=0;j<5;j++)
		{
		switch(j)
		{
		case 0:printf("\nMaths:");break;
		case 1:printf("Chemistry:");break;
		case 2:printf("Physics:");break;
		case 3:printf("Computer:");break;
		case 4:printf("Grade for SUPW:");break;
		}
		if(j==4)
		{
		scanf("%c",&e[i].grade);
		scanf("%c",&e[i].grade);
		}
		else
		{
		scanf("%d",&e[i].mark[j]);
		sum[j]=sum[j]+e[i].mark[j];
		}
		}
		}
	for(i=0;i<4;i++)
	{
	sum[i]=sum[i]/n;
	switch(i)
		{
		case 0:printf("The average for Maths is:");break;
		case 1:printf("The average for Chemistry is:");break;
		case 2:printf("The average for Physics is:");break;
		case 3:printf("The average for Computer is:");break;
		}
		printf("%.2f\n",sum[i]);
	}
}
