// to test a deep-nested struct
// this example tests a 2 nested struct
#define NULL ((void*)0)
struct nest1{
    int i;
    int j;
    char k;
};
struct nest0{
    int huga;
    long hoge;
    float aho;
    struct nest1 n1;
};
struct nest{
    char *str;
    char *p;
    void *env;
    code (*ret)(int);
    struct nest0 n0;
};
code
dmpn2(code(*ret)(int), void *env)
{
    goto ret(0), env;
}
code
dmpn1(struct nest1 *test1, code(*ret)(int), void *env)
{
    printf("dmpn1: %d %d %d\n",
	   test1->i,
	   test1->j,
	   test1->k);
    goto dmpn2(ret,env);
}
code
dmpn0(struct nest0 *test0, code(*ret)(), void *env)
{
    printf("dmpn0: %d %ld %f\n",
	   test0->huga,
	   test0->hoge,
	   test0->aho);
    goto dmpn1(&(test0->n1), ret, env);
}
code
dmpn(struct nest *test)
{
    printf("dmpn: %x %x\n", test->str, test->p);
    goto dmpn0(&(test->n0), test->ret, test->env);
}
void
dmp(struct nest *n)
{
    n->ret=return;
    n->env=environment;
    goto dmpn(n);
}
int
main()
{
    struct nest test;
    test.str=NULL;
    test.p=NULL;
    test.n0.huga=1;
    test.n0.hoge=2;
    test.n0.aho=3.0;
    test.n0.n1.i=10;
    test.n0.n1.j=20;
    test.n0.n1.k=30;
//    dmp(&test);
    return(0);
}
