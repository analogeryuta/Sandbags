/*
  memcpyのテストその2．
  今度は構造体のコピー．
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hoge {
    int i;
    char *str;
} Hoge;



int 
main()
{
    //int *dest;
    //int src=344445;
    Hoge src, *dest;

    src.i = 1024;
    src.str = "Hello World";

    dest = (Hoge *)malloc(sizeof(Hoge));
    memcpy(dest, &src, sizeof(src));

    printf("int value : src->%d, dest->%d\n",src.i, dest->i);
    printf("char string : src->%s, dest->%s\n", src.str, dest->str);

    return 0;
}
