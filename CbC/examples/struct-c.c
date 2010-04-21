extern int printf(char*,...);
struct obj {
    int i;
    char **arg;
};
int
main()
{
    struct obj o;
    char *str[3]={"aho", "huga", "hoge"};
    o.i=0;
    o.arg=str;
    for(o.i=0; o.i<3; o.i++){
	printf("%x\n", (unsigned long)o.arg[o.i]);
    }
    return 0;
}
