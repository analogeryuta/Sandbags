#include"my-stdio.h"
#define FOR_MAX 10

code
for0(int i,code (*ret)(int), void *env)
{
    if(i<FOR_MAX){
	i++;
	printf("hello\n");
	goto for0(i,ret,env);
    }
    goto ret(0),env;
}

int
main()
{
    goto for0(0,return,environment);
}
