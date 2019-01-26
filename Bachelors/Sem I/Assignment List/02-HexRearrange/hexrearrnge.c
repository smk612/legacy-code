/* C Program to rearrange given Hex code*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	unsigned int n;
	
	/*Read the input*/
	printf("Enter the Hex code:");
	scanf("%0x",&n);
	
	/*Rearranging the input according to the question*/
	printf("The rearranged code is:%0x\n",((n&0x00ff0000)>>16)|((n&0x000000ff)<<24)|((n&0xff000000)>>8)|(n&0x0000ff00));
	return 0;
}
