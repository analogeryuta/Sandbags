extern int printf(char*,...);
struct opt {
    char* p;
    int i;
    int argc;
    char** argv;
} option;

#if 0
code
opt1(struct opt o, code (*exit0)(int), void* env)
{
    printf("opt1: %x\n", (unsigned long)o.p);
    if(*(o.p)=='\0'){
	printf("\n");
	goto opt0(o, exit0, env);
    } else{
	printf("%c", *(o.p));
	o.p++;
	goto opt1(o, exit0, env);
    }
}
#endif

code
opt0(struct opt o, code (*exit0)(int), void* env)
{
    printf("opt0\n");
    
    if(o.i<o.argc){
//	o.p=o.argv[o.i];
//	printf("%s %d\n", *(o.argv), o.i);
	printf("%x\n", (unsigned long)(o.argv[o.i]));
	o.i++;
	goto opt0(o,exit0,env);
//	goto opt1(o, exit0, env);
    }
    goto exit0(0), env;
}
int
main()
{
    int i;
    char* arg[3]={
	"program",
	"--file",
	"ahoaho",
    };
    option.i=0;
    option.argc=3;
    option.argv=arg;
#if 1
    for(i=0; i<3; i++){
	printf("%x\n", (unsigned long)option.argv[i]);
    }
#endif
    goto opt0(option, return, environment);
    return 0;
}
