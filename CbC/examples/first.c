//#include <stdio.h>

code
code2(code (*exit0)(int), void *env)
{
    printf("aho\n");
    goto exit0(0), env;
}

code
code1(code *(exit0)(int), void *env)
{
    printf("hello\n");
    goto code2(exit0, env);
}

void
aho()
{
    goto code1(return,environment);    
}

int
main()
{
    aho();
    printf("finish\n");
    return 0;
}
