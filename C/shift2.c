//シフト演算の確認
#include <stdio.h>

#define R_LEFT         (1)
#define R_DOWN         (1 << 1)
#define R_UP           (1 << 2)
#define R_RIGHT        (1 << 3)
#define L1             (1 << 4)
#define R1             (1 << 5)
#define L2             (1 << 6)
#define R2             (1 << 7)
#define SELECT         (1 << 8)
#define START          (1 << 9)
#define L_LEFT         (1 << 10)
#define L_DOWN         (1 << 11)
#define L_UP           (1 << 12)
#define L_RIGHT        (1 << 13)


int
main(int argc, char *argv[])
{
    int a,b;
    
    a = 39;
    b = a >> 2;

    printf("before : %d\n", a);
    printf("after  : %d\n", b);

    printf("R_LEFT %p\n",R_LEFT);
    printf("R_DOWN %p\n",R_DOWN);
    printf("R_RIGHT %p\n", R_RIGHT);
    printf("R_UP %p\n",R_UP);
    printf("START %p\n",START);

    return 0;
}
