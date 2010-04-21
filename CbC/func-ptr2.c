/*
  関数ポインタ，構造体，構造体のtypedef,
  mallocのテスト．

  ここで定義してる構造体は interfaceと同義なのん?
  関数ポインタの引数は,敢えて設定せず．
*/
#include <stdio.h>

code (*ret)();
void *env;

typedef struct calc {
    code (*add)(int ,int);
    code (*func)();      //引数指定しなくても，これだけで行けるか?
} Calc;

code 
Add(int i, int j)
{
    int rslt;
    rslt = i+j;

    printf("Add start.\n");
    goto Print(rslt);
}

code
Multiple(int i, int j)
{
    int rslt;
    rslt = i*j;

    printf("multiple start\n");
    goto Print(rslt);
}

//計算結果の出力．
code
Print(int i)
{
    printf("Result: %3d\n", i);
    goto ret(0),env;
}

//計算の実行
code 
process(code (*exec)(int, int), int i, int j)
{
    printf("Calc start.\n");
    goto exec(i, j);
}

//実行する計算機の準備 -> 間接goto先の指定,引数の受渡し
code
setup(Calc *machine)
{
    //code (*exec)(int, int);
    goto process(machine->func, 5, 5);
}

//mallocによるメモリ確保, 計算を行うcode segmentのポインタを代入
code
Init(Calc *i)
{
    i = (Calc *)malloc(sizeof(Calc));
    i->add = Add;
    i->func = Multiple;

    goto setup(i);
}

int
main(int argc, char *argv[])
{
    Calc *calcurator;

    //return, environmentの設定は必須．
    ret = return;
    env = environment;
   
    goto Init(calcurator);
}
