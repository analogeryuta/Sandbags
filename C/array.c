#include <stdio.h>



int
main()
{
    int a[25];
    int c[25];
    int *b, *d;

    int i = 0;
    for (i=0; i<25; i++) {
	a[i] = i;
	c[i] = 0;
    }


    //配列の先頭要素受渡し
    b = &a[0];
    d = &c[0];

    int sum=0;
    for (i=0; i<25; i++) {
	if (*(d+i) == 0) {
	    sum += *(b+i);
	} 
	printf("%d\n", sum);
    }


    return 0;
}
