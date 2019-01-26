#include<stdio.h>
void main()
 {
 	int x;
 	printf("Enter the Month\n");
	scanf("%d",&x);
	switch(x)
	{
	case 1: case 3: case 5: case 7: case 8: case 10:   case 12:
	printf("The number of days is 31\n");
	break;
	case 4: case 6: case 9: case 11:
	printf("The number of days is 30\n");
	break;
	case 2: printf("The number of days is 28 in a non-leap year and 29 in a leap year\n");
	break;
	default : printf("Invalid input\n");
	}
	
 }
