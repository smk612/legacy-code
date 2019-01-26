#include <stdio.h>
#define ARRSIZE 10
void main()
{
    int i,max,min;
    int a[ARRSIZE];
    printf("Enter 10 elements of the array\n");
    for(i=0;i<10;i++)
    {
    scanf("%d",&a[i]);
    }
    min=a[0];
    max=a[0];
    for(i=0;i<10;i++)
    {
    if(a[i]>max)
    max=a[i];
    if(a[i]<min)
    min=a[i];
    }
    printf("The maximum is %d and the minimum is %d\n",max,min);
}

