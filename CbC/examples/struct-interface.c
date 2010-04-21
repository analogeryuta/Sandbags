// interfaceに1つだけのstructを使う
#include"my-stdio.h"
#define USE_BREAKP
#include"dbg.h"

struct interface {
    int a;
    int b;
    float c;
    int d;
    code (*ret)(int);
    void *env;
} intf;

code
testexit(struct interface *i)
{
    goto i->ret(0),i->env;
}

code
printit(struct interface *i)
{
    BREAKP(printit,i);
    printf("%d %d %f %d\n",i->a,i->b,i->c,i->d);
    goto testexit(i);
}

code
test0(struct interface *i)
{
    i->a=10;
    i->b=20;
    i->c=30;
    i->d=40;
    goto printit(i);
}

int
main()
{
    intf.ret=return;
    intf.env=environment;
    goto test0(&intf);
}
