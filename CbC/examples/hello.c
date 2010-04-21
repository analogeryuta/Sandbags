//はじめてのcbcプログラム．．．

//code (*exit0)(int);
void *env;

code 
state0(code (*exit0)(int), void *env)
{
    printf("first state\n");
    goto state1(exit0, env);
}

code 
state1(code (*exit0)(int), void *env)
{
    printf("second state\n");
    goto state2(exit0, env);
}

code 
state2(code (*exit0)(int), void *env)
{
    printf("third state\n");
    goto state3(exit0, env);
}


code 
state3(code (*exit0)(int), void *env)
{
    printf("this is the end...\n");
    goto exit0(0), env;
}

void
start()
{
    goto state1(return, environment);
}


int 
main()
{
    start();
    printf("finish!\n");
    return 0;
}
