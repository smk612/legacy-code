#include <stdio.h>
#include <stdlib.h>
struct Sparse
{
	int i,j,val;
};
int main()
{
	int r,c,i,j,w=1,x,y=1,z=1,m=0,n=0;
	printf("Enter size ::");
	scanf("%d %d",&r,&c);
	x=0.25*(r*c);
	struct Sparse a[x+1],b[x+1],d[x*2+1];
	a[0].i=r;
	a[0].j=c;
	a[0].val=0;
	b[0].i=r;
	b[0].j=c;
	b[0].val=0;
	d[0].i=r;
	d[0].j=c;
	d[0].val=0;
	printf("Enter elements of 1st matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&x);
			if(x!=0)
			{
				a[y].i=i;
				a[y].j=j;
				a[y].val=x;
				a[0].val++;
				y++;
			}
		}
	}
	printf("Enter elements of 2nd matrix:\n");
	y=1;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&x);
			if(x!=0)
			{
				b[y].i=i;
				b[y].j=j;
				b[y].val=x;
				b[0].val++;
				y++;
			}
		}
	}
	y=1;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			m=0;n=0;x=0;
			if(a[y].i==i&&a[y].j==j)
				m=1;
			if(b[z].i==i&&b[z].j==j)
				n=1;
			if(m==1&&n==1)
			{
				if(a[y].val+b[z].val!=0)
					x=a[y].val+b[z].val;
				y++;z++;
			}
			if(m==1&&n==0)
			{
				x=a[y].val;
				y++;
			}
			if(m==0&&n==1)
			{
				x=b[z].val;
				z++;
			}
			if(x!=0)
			{
				d[w].i=i;
				d[w].j=j;
				d[w].val=x;
				d[0].val++;
				w++;
			}
		}
	}
	w=1;
	printf("The Final Matrix is:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(d[w].i==i&&d[w].j==j)
			{
				//printf("%d\t",d[w].val);
				printf("%d %d - %d\n",d[w].i,d[w].j,d[w].val);
				w++;
			}	
			//else
				//printf("0\t");
		}
		//printf("\n");
	}
	return 0;
}
