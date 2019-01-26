#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void main(int argc,char *argv[])
{
	int i;
	double res=0,op=0;
	char c;
	if(argc>1)
	{
	res = atof(*(++argv));
		for(i=1;i<argc;i++,argv++)
		{
			if(isdigit(*(*argv)))
			{
				op=atof(*argv);
				if(c=='+')
				res=res+op;
				if(c=='-')
				res=res-op;
				if(c=='x')
				res=res*op;
				if(c=='/')
				res=res/op;
			}
			else
			c=*(*argv);
			printf("%f\t%f\t%c||",res,op,c);
			printf("%p %p\n",argv,*argv);
		}
	printf("The result is %f\n",res);
	}
}
