#include<stdio.h>
main()
{
	int i,j,n;
printf("enter the array size \n");
scanf("%d",&n);
	int arr[n];


	for(i=0;i<n;i++){
	scanf("%d\n",&arr[i]);}
	
for(i=0;i<n;i++){
	for(j=0;j<n-1;j++){
		if(arr[j]>arr[j+1]){
			int tmp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=tmp;}
	}	}

for(i=0;i<n;i++){
	printf("%d--",arr[i]);}
}
