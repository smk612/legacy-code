#include <stdio.h>
void main()
{
   unsigned int n,r,s;
   printf("Enter 8 digit hexadecimal number\n");
   scanf("%x",&n);
   r=n&0x00ffff00;//To set all bits except middle 8 as 0
   s=n>>24|n<<24|(r<<8&0x00ffff00)|(r>>8&0x00ffff00);
   printf("The swapped hexadecimal is %x \n",s);
}

