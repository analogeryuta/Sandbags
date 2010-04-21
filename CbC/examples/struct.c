// to test the code segment interface unsing struct pointer
extern int printf(char*,...);
struct interface {
    int num; char **arg; code (*ret)(); void *env;
};
code
aho1(struct interface *intf)
{
    goto intf->ret(),intf->env;
}
code
aho0(struct interface *intf, int i)
{
    if(i < intf->num){
	printf("%s (%x)\n",intf->arg[i],(unsigned long)intf->arg[i]);
	i++;
	goto aho0(intf, i);
    }
    goto aho1(intf);
}
void
aho(struct interface *intf)
{
    goto aho0(intf, 0);
}
int
main()
{
    struct interface intf;
    char *str[3]={"aho", "huga", "hoge"};
    intf.num=3; intf.arg=str; intf.ret=return; intf.env=environment;
    aho(intf);
//    goto aho0(intf,0);		// will cause a serious error
}
