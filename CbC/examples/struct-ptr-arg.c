extern int printf(char*,...);
struct interface {
    int i;
    int num;
    char **arg;
    code (*ret)();
    void *env;
};
void
huga(struct interface *intf)
{
    printf("%x\n", (unsigned long)intf);
}
int
main()
{
    struct interface a;
    struct interface *b=&a;
    printf("%x\n", (unsigned long)b);
    b->i=1;
    b->num=2;
    b->arg=(void*)3;
    b->ret=return;
    b->env=environment;
    huga(b);
    return(0);
}
