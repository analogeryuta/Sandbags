#include"my-stdio.h"

#define OBJECT_MAXNUM 10

#define _BUG

#ifdef _BUG
struct {
    float j;			// bug
    int i;
    int k;
    int h;
} a[OBJECT_MAXNUM];

#else

struct {
    int i;
    int j;
    int k;
    int h;
} a[OBJECT_MAXNUM];
#endif // _BUG

code
print_a(int i,code(*ret)(int),void *env)
{
    if(i<OBJECT_MAXNUM){
#ifdef _BUG
	printf("a[%d]: i=%d j=%f k=%d h=%d\n", i, a[i].i,a[i].j,a[i].k,a[i].h);
#else
	printf("a[%d]: i=%d j=%d k=%d h=%d\n", i, a[i].i,a[i].j,a[i].k,a[i].h);
#endif
	i++;
	goto print_a(i,ret,env);
    }
    goto ret(0),env;
}

code
init_a(int i,code(*ret)(int),void *env)
{
    if(i<OBJECT_MAXNUM){
	a[i].i=1;
	a[i].j=2;
	a[i].k=3;
	a[i].h=4;
	i++;
	goto init_a(i,ret,env);
    }
    goto print_a(0,ret,env);
}

int
main()
{
    goto init_a(0,return,environment);
    return(0);
}
