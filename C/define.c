#include <stdio.h>

#define   func(x)   (x)*(x)

int
main()
{
    int x, y;

    //x = 5;
    y = func(5);

    printf("%d\n", y);

    return 0;
}
