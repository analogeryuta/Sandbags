extern int printf(char*,...);
code
opt1(char* p, int i, int argc, char** argv, (*exit0)(int), void* env)
{
    if(*p=='\0'){
	printf("\n");
	goto opt0(i, argc, argv, exit0, env);
    } else{
	printf("%c", *p);
	p++;
	goto opt1(p, i, argc, argv, exit0, env);
    }
}
code
opt0(int i, int argc, char** argv, (*exit0)(int), void* env)
{
    char* p;
    if(i<argc){
	p=argv[i];
	i++;
	goto opt1(p, i, argc, argv, exit0, env);
    }
    goto exit0(0), env;
}
int
main()
{
    char* arg[3]={"program","--file","ahoaho"};
    goto opt0(1, 3, arg, return, environment);
    return 0;
}
