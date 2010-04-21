#include"my-stdio.h"

#define OBJECT_MAXNUM 10

struct test {
    int i;
    float j;
    int k;
    int h;
} a[OBJECT_MAXNUM];

code
print_a(struct test *b,int q,code(*ret)(int),void *env)
{
    if(q<OBJECT_MAXNUM){
	printf("a[%d]: i=%f j=%d k=%d h=%d\n",
	       q, b[q].i,b[q].j,b[q].k,b[q].h);
	q++;
	goto print_a(b,q,ret,env);
    }
    goto ret(0),env;
}

code
init_a(struct test *b,int q,code(*ret)(int),void *env)
{
    if(q<OBJECT_MAXNUM){
	b[q].i=1;
	b[q].j=2;
	b[q].k=3;
	b[q].h=4;
	q++;
	goto init_a(b,q,ret,env);
    }
    goto print_a(b,0,ret,env);
}

int
aho()
{
    goto init_a(a,0,return,environment);
}

int
main()
{
    aho();
    return(0);
}
