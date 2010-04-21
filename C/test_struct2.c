/*
  構造体のテストその2
  呼び出した関数内での値の代入とか．
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test{
    int a;
    int b;
    int c;
    int d;
} TEST, *TEST_Ptr;

void init_func1(TEST_Ptr ptr);
void init_func2(TEST *i);
TEST global;                 //構造体変数を大域変数として宣言

int 
main()
{
    TEST *test1, test2;
    test1 = (TEST *)malloc(sizeof(TEST));

    //mallocを使った場合
    init_func1(test1);
    printf("test1 : %d, %d, %d, %d\n", test1->a, test1->b, test1->c, test1->d);

    //malloc()を使わない場合
    init_func2(&test2);
    printf("test2 : %d, %d, %d, %d\n",test2.a,test2.b,test2.c,test2.d);

    //大域変数を使ってみる(mallocは使わない)
    init_func2(&global);
    printf("gloval value : %d, %d, %d, %d\n",global.a,global.b,global.c,global.d);

    free(test1);   //free()を忘れずに．
    return 0;
}

void 
init_func1(TEST_Ptr ptr)
{
    ptr->a = 0;
    ptr->b = 10;
    ptr->c = 10;
    ptr->d = 0;

    //printf("%d, %d, %d, %d\n", ptr->a, ptr->b, ptr->c, ptr->d);
}

void 
init_func2(TEST *val)
{
    /*
    //関数内部で構造体の変数を宣言，値を設定
    TEST i;
    i.a = 0;
    i.b = 0;
    i.c = 0;
    i.d = 0;
    */

    //malloc()でメモリ領域確保，その値をmemcpyしてみる
    TEST_Ptr i;
    i = (TEST_Ptr )malloc(sizeof(TEST));

    i->a = 0;
    i->b = 20;
    i->c = 0;
    i->d = 500;
    //関数内部での様子は？
    printf("init_func2 : %d, %d, %d, %d\n", i->a, i->b, i->c, i->d);

    //ここでmemcpy使ったらどうなる?
    memcpy(val, i, sizeof(i));    
    free(i);
}
