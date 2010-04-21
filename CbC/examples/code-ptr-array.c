extern int printf(char*,...);
code
aho0(int *i, code(*ret)(), void *env)
{
    printf("aho%d\n", *i);
    (*i)++;
    goto ret(),env;
}
void
aho()
{
    static int i=0;
    goto aho0(&i,return,environment);
}
code(*lis[5])()={
    aho0,
    aho0,
    aho0,
    aho0,
    (void*)0,
};
int
main()
{
    int i;
    for(i=0;i<5;i++){
	aho();
    }
    return(0);
}
