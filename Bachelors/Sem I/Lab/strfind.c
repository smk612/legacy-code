#include <stdio.h>
#include <stdlib.h>
void main()
{
	int i,bl,j,k,c,flag=0;
	char a[50],b[10];
	printf("Enter sentence\n");
	fgets(a,50,stdin);
	printf("Enter keyword\n");
	fgets(b,10,stdin);
	for(i=0;b[i]!='\0';i++);
	bl=i-1;
	for(i=0;i<50-bl;i++)
	{
		c=0;
		for(j=i,k=0;k<=bl;j++,k++)
		{
			if(a[j]==b[k])
			c++;
		}
		if(c==bl)
		{
		printf("Found string at %d\n",i);
		flag=1;	
		}
	}
	if(flag==0)
	printf("String not found\n");	
}
