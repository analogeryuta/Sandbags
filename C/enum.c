#include <stdio.h>

typedef enum {
    ONE=2,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN
} NUMBERS;

int
main()
{
    NUMBERS num;

    num = ONE;
    printf("%d\n", num);

    num = TWO;
    printf("%d\n", num);

    num = THREE;
    printf("%d\n", num);

    num = FOUR;
    printf("%d\n", num);

    num = FIVE;
    printf("%d\n", num);

    return 0;
}
