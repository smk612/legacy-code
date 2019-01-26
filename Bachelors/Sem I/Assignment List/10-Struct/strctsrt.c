/*C Program to Sort through structures*/
#include <stdio.h>
#include <string.h>
#define N 5

/*Create Structure*/
struct student
{
	char name[50];
	int mark[4];
	double avg;
};
int main()
{
	int i,j,flag=1,tmpa[4];
	char tmpn[50];
	double tmp,sum=0;
	struct student e[N];
	
	/*Read the Individual Inputs*/
	printf("Enter the details of the students\n");
	for(i=0;i<N;i++)
	{	
		printf("-----------------------------------%d-----------------------------------\n",i+1);
		printf("Name:");
		scanf("%[^\n]s",&e[i].name);
		printf("Enter Marks for %s",e[i].name);
		sum=0;
		for(j=0;j<4;j++)
		{	
			switch(j)
			{
				case 0:printf("\nScience:");break;
				case 1:printf("Mathematics:");break;
				case 2:printf("English:");break;
				case 3:printf("Bengali:");break;
			}
			scanf("%d",&e[i].mark[j]);
			sum=sum+e[i].mark[j];
		}
		getchar();
		e[i].avg=sum/N;
	}
	
	/*Sort the structures*/
	while(flag)
	{
		flag=0;
		for(i=0;i<N-1;i++)
		{
			if(e[i].avg<e[i+1].avg)
			{
				
				/*Swapping all the elements of the structures*/
				tmp=e[i].avg;
				e[i].avg=e[i+1].avg;
				e[i+1].avg=tmp;
				strcpy(tmpn,e[i].name);
				strcpy(e[i].name,e[i+1].name);
				strcpy(e[i+1].name,tmpn);
				for(j=0;j<4;j++)
				{
					tmpa[j]=e[i].mark[j];
					e[i].mark[j]=e[i+1].mark[j];
					e[i+1].mark[j]=tmpa[j];
				}
				flag=1;
			}
		}
	}
	
	/*Print Sorted Structures*/
	printf("-----------------------------------------------------------------------\n");
	printf("------------------------The Sorted Structure is------------------------\n");
	for(i=0;i<N;i++)
	{
		printf("-----------------------------------------------------------------------\n");
		printf("Name:%s\n",e[i].name);
		for(j=0;j<4;j++)
		{
			switch(j)
			{
				case 0:printf("Science:%6d\t",e[i].mark[j]);break;
				case 1:printf("Mathematics:%6d\t",e[i].mark[j]);break;
				case 2:printf("English:%6d\t",e[i].mark[j]);break;
				case 3:printf("Bengali:%6d\n",e[i].mark[j]);break;
			}
		}
		printf("Average:%6.2lf\n",e[i].avg);
	}
	printf("-----------------------------------------------------------------------\n");
	return 0;
}
