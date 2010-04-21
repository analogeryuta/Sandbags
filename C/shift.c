//シフト演算の確認
#include <stdio.h>


int
main(int argc, char *argv[])
{
    int a,b;
    
    a = 39;
    b = a >> 2;

    printf("before : %d\n", a);
    printf("after  : %d\n", b);

    return 0;
}
