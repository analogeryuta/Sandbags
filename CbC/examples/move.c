extern printf(char*,...);
struct enemy {
    code(*ret)(int);
    void *env;
};
code
my_exit(struct enemy *interface)
{
    goto interface->ret(0),interface->env;
}
code
enemygo1(struct enemy *interface)
{
    printf("enemygo1\n");
    goto my_exit(interface);
}
code
enemygo2(struct enemy *interface)
{
    printf("enemygo1\n");
    goto my_exit(interface);
}
code
enemygo3(struct enemy *interface)
{
    printf("enemygo1\n");
    goto my_exit(interface);
}
code
enemygo4(struct enemy *interface)
{
    printf("enemygo1\n");
    goto my_exit(interface);
}
#if 0
code (*go)(struct enemy *) list[4]={
    enemygo1,
    enemygo2,
    enemygo3,
    enemygo4
};
#endif

//code (*)(struct endif *) *lis=enemygo1;
code (*lis)(struct enemy *)[]={enemygo1};

code
enemygo(int behav,struct enemy *interface)
{
    if(behav==1){
	goto enemygo1(interface);
    }else if(behav==2){
	goto enemygo1(interface);
    }else if(behav==3){
	goto enemygo1(interface);
    }else if(behav==4){
	goto enemygo1(interface);
    }
    goto my_exit(interface);
}
int
main()
{
    struct enemy interface;
    interface.ret=return;
    interface.env=environment;
    goto enemygo(1,&interface);
}
