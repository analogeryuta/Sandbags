#include <stdio.h>


int
main()
{
    int *pDes,*pSrc;
    int i=0;
    int j=0;

    pDes = &i;
    pSrc = &j;
    printf("%d, %d\n",*pDes,*pSrc);

    *pDes++ = *pSrc++;
    printf("%d, %d\n",*pDes,*pSrc);

    *pDes++ = *pSrc++;
    printf("%d, %d\n",*pDes,*pSrc);


    return 0;
}
