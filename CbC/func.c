#include <stdio.h>

code (*ret)();
void *env;

code 
hoge0(int i)
{
    printf("%d : kiterukai?\n", i);
    goto hoge1(i);
}

code 
hoge1(int i)
{
    i++;
    printf("%d : kiterunee!\n", i);

    /*
      このgoto により，最初の呼び出し元(void start())
      へreturnする．
    */
    goto ret(++i),env; 
}

int
start(int i)
{
    
    //return, environment を代入することを忘れるな!!
    ret = return;
    env = environment;

    goto hoge0(i);
}

int
main()
{
    int num=5;
    int ret_check=0;

    ret_check=start(num);
    printf("%d: finish\n", ret_check);

    return 0;
}
