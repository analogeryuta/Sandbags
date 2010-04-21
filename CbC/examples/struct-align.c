/* to test the struct alignment */
#include"my-stdio.h"

struct test{
    int a;
    int b;
    int c;
    float d;
} foo;

code
print_foo(code(*ret)(int),void *env)
{
    printf("a=%d b=%d c=%d d=%f\n",foo.a,foo.b,foo.c,foo.d);
    goto ret(0),env;
}
code
init_foo(code(*ret)(int),void *env)
{
    foo.a=1;
    foo.b=2;
    foo.c=3;
    foo.d=4;
    goto print_foo(ret,env);
}
int
main()
{
    goto init_foo(return,environment);
    return(0);
}
