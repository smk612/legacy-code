#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//main(int argc,char *argv[])
main()
{
	FILE *fp,*fp1;
	char ch[512];
	int flag=1;
	/*if(argc!=2)
	{
		printf("You forgot to enter the filename\n");
		exit(1);
	}*/
	system("ls > name.txt");
	if((fp=fopen("name.txt","r"))==NULL)
	{
		printf("Cannot open file\n");
		exit(2);
	}
	fscanf(fp,"%[^\n]s",&ch);
	for(;getc(fp)!='\n';);
	printf("%s\t",ch);
	while(!feof(fp))
	{	
		if(!strcmp(ch,"a.out"))
			flag=0;
		else if(!strcmp(ch,"name.txt"))
			flag=0;
		else if(strrchr(ch,'.')==NULL)
			flag=0;
		else
			flag=1;
		if(flag)
		{	
			printf("%s\n",ch);
			if((fp1=fopen(ch,"w"))==NULL)
			{
			printf("Cannot open file\n");
			exit(2);
			}
			fclose(fp1);
		}
	fscanf(fp,"%[^\n]s",&ch);
	for(;getc(fp)!='\n';);
	printf("%s\t",ch);
	}
	printf("HEHEHE!!!!!!!!see ya");
	fclose(fp);
}
