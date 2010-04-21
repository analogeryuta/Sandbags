#include <stdio.h>

int
main(int argc, char *argv[])
{
    char c = 0xf;              //8ビット(正・負両範囲)
    unsigned char c_1 = 0xff;  //8ビット(正の整数のみ)
    int i = 0xffff;            //32ビット
    short int i_1 = 0xfff1;    //16ビット

    printf("c : %d\n",c);
    printf("c_1 : %d\n",c_1);
    printf("i : %d\n",i);
    printf("i_1 : %d\n",i_1);

    return 0;
}
