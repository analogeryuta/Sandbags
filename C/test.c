#include <stdio.h>

int
main(int argc, char *argv[])
{
    int test1, test2;//, test3;
    int buf = 2045;

    char *pad = (char *)(&buf);

    test1 = (int)(*(pad));
    //キャストの確認
    test2 = *((int *)(pad));
    //    test3 = *(&buf);

    printf("test1 = %d \n", test1);
    printf("test2 = %d \n", test2);
    //    printf("test3 = %d \n", test3);

    return 0;
}
