#include <stdio.h>
#include <stdlib.h>

typedef struct hoge {
    int i;
    int j;
} Hoge;

void
CheckPrint()
{
    Hoge *hoge1, *hoge2;

    hoge1 = (Hoge *)malloc(sizeof(Hoge));
    hoge2 = (Hoge *)malloc(sizeof(Hoge));

    hoge1 = NULL;
    hoge2->i=1; hoge2->j=5;

    if (!hoge1) {
	printf("hoge1 : Empty\n");
    } else {
	printf("hoge1: %d, %d\n", hoge1->i, hoge1->j);
    }

    if (!hoge2) {
	printf("hoge2 : Empty\n");
    } else {
	printf("hoge2: %d, %d\n", hoge2->i, hoge2->j);
    }

}

int
main()
{
    CheckPrint();
    return 0;
}
