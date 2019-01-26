#include <stdio.h>
#define ARRSIZE 10
void main()
{
    int i;
    int a[ARRSIZE],b[ARRSIZE],c[ARRSIZE];
    printf("Enter elements of 1st array\n");
    for(i=0;i<10;i++)
    {
    scanf("%d",&a[i]);
    }
    printf("Enter elements of 2nd array\n");
    for(i=0;i<10;i++)
    {
    scanf("%d",&b[i]);
    }
    for(i=0;i<10;i++)
    {
    c[i]=a[i]+b[i];
    printf("%d ",c[i]);
    }
    printf("\n");
}

