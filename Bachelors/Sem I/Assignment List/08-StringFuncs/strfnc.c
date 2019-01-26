/*C Program containing functions for String operations*/
#include "size.h"

/*Function to Copy String*/
int strcopy(char *a,char *b)
{	
	int i,k=0;
	for(i=0;a[i]!='\0';i++)
	{
		b[k++]=a[i];
	}
	b[k]='\0';
	return 0;
}

/*Function to Reverse a String*/
int strrev(char* a)
{
	int i,k;
	char tmp;
	for(i=0;a[i]!='\0';i++);
	k=i-1;
	for(i=0;i<=k/2;i++)
	{
		tmp=a[i];
		a[i]=a[k-i];
		a[k-i]=tmp;
	}
	a[k+1]='\0';
	return 0;
}

/*Function to Concat two Strings*/
int strconcat(char* a,char* b,char* c)
{
	int i,k=0;
	for(i=0;a[i]!='\0';i++)
	{
		c[k++]=a[i];
	}
	c[k++]=' ';
	for(i=0;b[i]!='\0';i++)
	{
		c[k++]=b[i];
	}
	c[k]='\0';
	return 0;
}
