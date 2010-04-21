/*
 *  配列を引数にとるcode segmentの記述テスト
 */
#include <stdio.h>

code (*ret)();
void *env;

typedef int Hoge[4][4];
Hoge hoge;

code 
printArray(Hoge arry, code (*ret)(), void *env)
{
    arry[1][1] = 10004;
    printf("arry[1][1]: %d\n", arry[1][1]);

    goto ret(0),env;
}

int
main()
{
    ret = return;
    env = environment;
    hoge[1][1]=1;
    printf("start : %d\n", hoge[1][1]);

    goto printArray(hoge, ret, env);
}
