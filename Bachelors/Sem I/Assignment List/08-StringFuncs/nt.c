/*C Program to perform String operations*/
#include "size.h"
int main()
{
	int ch=0;
	char ori[STRNGSIZE],cop[STRNGSIZE],concat[STRNGSIZED];
	
	/*Display Menu to the user*/
	do
	{
		printf("Menu:\n1)String Copy\n2)String Reversal\n3)String Concat\n4)Exit\n");
		scanf("%d",&ch);
		getchar();
		
		/*Call function corresponding to user choice*/
		switch(ch)
		{
			case 1: printf("Enter String to be copied: ");
					scanf("%[^\n]s",&ori);
					strcopy(ori,cop);
					printf("The copied String is: %s\n",cop);
					break;
			case 2: printf("Enter String to be reversed: ");
					scanf("%[^\n]s",&ori);
					strrev(ori);
					printf("The reversed String is: %s\n",ori);
					break;		
			case 3: printf("Enter 1st String: ");
					scanf("%[^\n]s",&ori);
					getchar();
					printf("Enter 2nd String: ");
					scanf("%[^\n]s",&cop);
					strconcat(ori,cop,concat);
					printf("The concatenated String is: %s\n",concat);
					break;
			case 4: return 1;
					break;
			default:printf("Invalid Choice\n");
		}
	}
	while(ch!=4);
	return 0;
}
