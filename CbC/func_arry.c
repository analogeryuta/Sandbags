/*
  関数ポインタの配列を作ってみるテスト
*/
#include <stdio.h>

code (*ret)();
void *env;

code 
hoge()
{
    printf("hoge\n");
    goto ret(0), env;
}

code 
fuga()
{
    printf("fuga\n");
    goto ret(0), env;
}

int
main()
{
    ret = return;
    env = environment;

    code (*func_ptr[])() = {hoge, fuga};
    goto (func_ptr[0])();
}
