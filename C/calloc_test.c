/* calloc_test.c : 配列をmallocするテスト。
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//intの配列を生成する
int* 
init_calloc(size_t size)
{
    int *p_arry=NULL;
    int cnt;

    p_arry = (int *)calloc(size, sizeof(int));
    if (!p_arry) {
	fprintf(stderr,"error: cannot allocate.\n");
    } else {
	for (cnt=0; cnt<size; cnt++) {
	    p_arry[cnt] = cnt;
	}
    }
    return p_arry;
}

int**
init_array(size_t size)
{
    int **p_double;
    int cnt;

    p_double = (int **)calloc(size, sizeof(int *));
    if (!p_double) {
	fprintf(stderr,"error: cannot allocate p_double \n");
	exit(1);
    } else {
	for (cnt=0; cnt<size; cnt++) {
	    p_double[cnt] = init_calloc(size);
	}
    }
    return p_double;
}

void 
print_arry(int *ptr, size_t size)
{
    int *arry=ptr;
    int cnt;
    for (cnt=0; cnt<size; cnt++) {
	printf("value ... %d\n", arry[cnt]);
    }
}

int
main()
{
    int *p_arry;
    int **p_double;
    int cnt, cnt2;
    size_t size=10;

#if 0
    p_arry=init_calloc(size);
    if (!p_arry) {
	fprintf(stderr,"error: array allocation failed.\n");
	exit(1);
    } else {
	for (cnt=0; cnt<size; cnt++) {
	    printf("value ... %d\n", p_arry[cnt]);
	}
    }
    free(p_arry);
#else
    p_double = init_array(size);
    if (!p_double) {
	fprintf(stderr,"error: array allocation failed.\n");
	exit(1);
    } else {
	//2次元配列としてアクセスできるか調べる
	for (cnt=0; cnt<size; cnt++) {
	    printf("line %d\n", cnt);
	    for (cnt2=0; cnt2<size; cnt2++) {
		printf("%d\n", p_double[cnt][cnt2]);
	    }
	}
    }
    //全部freeする。
    for (cnt=0; cnt<size; cnt++) {
	if (p_double[cnt]) free(p_double[cnt]);
    }
    free(p_double);
#endif

    return 0;
}
