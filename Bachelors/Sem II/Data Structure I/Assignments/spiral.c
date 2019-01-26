#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j,r,c,ch=0,e=0,ur,uc,lr=0,lc=0;
	printf("Enter size ::");
	scanf("%d %d",&r,&c);
	ur=r-1;
	uc=c-1;
	int **a=(int **)malloc(r*sizeof(int *));
	if(!a)
	{
		printf("Allocation failed");
		return 2;
	}
	for(i=0;i<r;i++)
		{
			a[i]=(int*)malloc(c*sizeof(int));
			if(!a[i])
			{
				printf("Allocation failed");
				return 1;
			}
		}
	i=0;
	while(e<r*c)
	{
	    if(ch%2==0)
	    {
	        for(j=lc;j<=uc;j++)
	        {
	            printf("Enter element at %d %d::\t",i,j);
	            scanf("%d",&a[i][j]);e++;
	        }
	        lr++;j--;
	        for(i=lr;i<=ur;i++)
	        {
	             printf("Enter element at %d %d::\t",i,j);
	            scanf("%d",&a[i][j]);e++;
	        }
	        uc--;i--;
	    }
	    else
	    {
	        for(j=uc;j>=lc;j--)
	        {
	             printf("Enter element at %d %d::\t",i,j);
	            scanf("%d",&a[i][j]);e++;
	        }
	        ur--;j++;
	        for(i=ur;i>=lr;i--)
	        {
	            printf("Enter element at %d %d::\t",i,j);
	            scanf("%d",&a[i][j]);e++;
	        }
	        lc++;i++;
	    }
	    ch++;
	}
	printf("The Matrix is ::\n");
	for(i=0;i<r;i++)
	{
	    for(j=0;j<c;j++)
	    {
	        printf("%d\t",a[i][j]);
	    }
	    printf("\n");
	}
	return 0;		
}
