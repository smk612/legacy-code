/*C Program to print the reverse of a File */
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	FILE *fp;
	int i;
	char ch;
	long count;
	
	/*Check if file name entered or not*/
	if(argc!=2)
	{
		printf("You forgot to enter the filename\n");
		exit(1);
	}
	
	/*Display error message if file pointer could not be loaded*/
	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot open file\n");
		exit(2);
	}
	
	/*Display the contents of the file*/
	printf("The file is:\n");
	ch=getc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=getc(fp);
	}
	
	/*Take file pointer to EOF*/
	fseek(fp,-1L,SEEK_END);
	count=ftell(fp);
	printf("The Reverse of the file is:");
	
	/*Print reverse of the file*/
	while(count!=-1)
	{
		ch=getc(fp);
		putchar(ch);
		fseek(fp,-2L,SEEK_CUR);
		count--;
	}
	printf("\n");
	
	/*Close the original file to avoid damage*/
	fclose(fp);
	return 0;
}
