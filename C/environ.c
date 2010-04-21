#include <stdio.h>


int 
main(int argc, char *argv[])
{
    int i;
    char *p;
    extern char **environ;  //環境を持つ大域変数
    
    for (i=0; environ[i]!=(char *)0; i++)
	printf("%d %s\n", i, environ[i]);

  return 0;
}
