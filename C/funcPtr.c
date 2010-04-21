#include <stdio.h>
#include <stdlib.h>

//適当な関数
void
PrintStr()
{
    printf("this is a pen\n");
}
//てきとうな関数その2
int
PrintNum(int num)
{
    printf("Input num is %d\n", num);
    return 0;
}

//関数のポインタ
void (*funcPtr)();
//仮引数付きの関数ポインタ
int (*funcPtr2)(int );

int 
main(int argc, char *argv[])
{
    //普通に関数呼出し
    PrintStr();

    //ポインタから関数呼出し
    funcPtr = PrintStr;
    funcPtr();

    //ポインタから呼出その2
    int num = 5;
    funcPtr2 = PrintNum;
    funcPtr2(num); 

    return 0;
}
