#include <stdio.h>
#include <stdlib.h>

int 
main()
{
    char *a = (char *)malloc(sizeof(char));
    int *b = (int *)malloc(sizeof(int)*10);
    int cnt;

    //allocateした領域へのポインタを確認
    for (cnt=0; cnt<10; cnt++) {
	printf("ptr : %p\n", &b[cnt]);
    }

    for (cnt=0; cnt<10; cnt++) {
	b[cnt]=cnt;
    }
    //テストその1
    a = "hogehoge";
    printf("%s\n", a);

    for (cnt=0; cnt<10; cnt++) {
	printf("%d\n", b[cnt]);
    }

    return 0;
}
