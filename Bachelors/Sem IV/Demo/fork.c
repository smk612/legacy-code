#include <stdio.h>   /* printf, stderr, fprintf */
#include <unistd.h>  /* _exit, fork */
 
int main(void)
{
   pid_t  pid;

   pid = fork();
   if (pid == 0)
   {
	printf("\n\tAm child, my id is: %d My Parent is: %d\n",getpid(),getppid());
   }
   else if (pid > 0)
   { 
	printf("\n\tAm parent, my id is: %d My Parent is: %d\n",getpid(),getppid());
   }
   
}

