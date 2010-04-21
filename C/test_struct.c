#include <stdio.h>
#include <stdlib.h>

typedef struct test{
    int a;
    int b;
    int c;
    int d;
} TEST, *TEST_Ptr;

void init_func1(TEST_Ptr ptr);
void init_func2(TEST i);

int 
main()
{
    TEST *test1, test2;
    test1 = (TEST *)malloc(sizeof(TEST));

    init_func1(test1);
    init_func2(test2);

    return 0;
}


void 
init_func1(TEST_Ptr ptr)
{
    ptr->a = 0;
    ptr->b = 0;
    ptr->c = 0;
    ptr->d = 0;

    printf("%d, %d, %d, %d\n", ptr->a, ptr->b, ptr->c, ptr->d);
}

void 
init_func2(TEST i)
{
    i.a = 0;
    i.b = 0;
    i.c = 0;
    i.d = 0;

    printf("%d, %d, %d, %d\n", i.a, i.b, i.c, i.d);
}
