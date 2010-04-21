#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
main()
{
    int *dest;
    int src=344445;

    dest = (int *)malloc(sizeof(int));
    memcpy(dest, &src, sizeof(src));

    printf("src:%d\n", src);
    printf("dest:%d\n", *dest);

    return 0;
}
