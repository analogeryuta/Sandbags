#include <stdio.h>
#include <stdlib.h>

//適当なポインタ
void *(*ptr)();

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

//てきとうな関数その3
char *
outString()
{
    char *str = "hogehogefuga";
    return str;
}

//関数のポインタ
void (*funcPtr)();

//戻り値の型付き,関数ポインタ
int (*funcPtr2)();

//こういうのはどう?
void* (*funcPtr3)();

int 
main(int argc, char *argv[])
{
    //普通に関数呼出し
    PrintStr();


    //ポインタから関数呼出し
    funcPtr = &PrintStr;
    funcPtr();

    //ポインタから呼出その2
    int num = 5;
    funcPtr2 = &PrintNum;
    funcPtr2(num); 

    //その3
    char *str="not input.";
    funcPtr3 = (void*)&outString;
    str = funcPtr3();
    printf("%s\n", str);

    return 0;
}
