#include <stdio.h>
void main()
{
        int x,y,i,j,m,n,k=0,l=0;
        printf("Enter the order of the array\n");
        scanf("%d %d",&x,&y);
        int a[x][y],b[x-1][y-1];
        printf("Enter the elements of the array\n");
        for(i=0;i<x;i++)
        {
        for(j=0;j<y;j++)
        {
        scanf("%d",&a[i][j]);
        }
        }
        for(i=0;i<x;i++)
        {
        for(j=0;j<y;j++)
        {
        printf("%d\t",a[i][j]);
        }
        printf("\n");
        }
        printf("Enter the index of the element to be deleted\n");
        scanf("%d %d",&m,&n);
        for(i=0;i<x;i++)
        {
        for(j=0;j<y;j++)
        {
        if(i==m||j==n);
        else
        b[k][l++]=a[i][j];
        if(l==n-2)
        k++;
        }
        }
        printf("Output Matrix is\n");
        for(i=0;i<x-1;i++)
        {
        for(j=0;j<y-1;j++)
        {
        /*if((i==m)||(j==n))
        continue;*/
        printf("%d\t",b[i][j]);
        }
        printf("\n");
        }
}
