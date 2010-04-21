/* calloc_struct_array.c : 構造体の配列をmallocするテスト。
 * 四則演算の関数を持つ構造体リストを作り、入力に従って演算結果を
 * stdout に出力するのさ。
 * こんなかんじ...
 *
 * [prompt]% ./calc -add 7 3
 *  result : 10
 * [prompt]% 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hoge.h"

//足し算をおこなう。
int
add(HogePtr h)
{
    return h->x + h->y;
}

//引き算をおこなう。
int
sub(HogePtr h)
{
    return h->x - h->y;;
}

//かけ算をおこなう。
int
mult(HogePtr h)
{
    return h->x * h->y;
}

//割り算をおこなう。
int 
divid(HogePtr h)
{
    if (h->y > 0) {
	return h->x / h->y;
    } else {
	fprintf(stderr,"error : can't divide x by 0\n");
	exit (EXIT_FAILURE);
    }
    return ;
}

//長さsizeの配列を生成する
HogePtr
init_calloc(size_t size)
{
    HogePtr p_arry=NULL;

    p_arry=(Hoge *)calloc(size, sizeof(Hoge));
    if (!p_arry) {
	fprintf(stderr,"cannot allocate array\n");
    } else {
    }
    return p_arry;
}

void 
print_arry(HogePtr ptr, size_t size)
{

}

int
main()
{
    HogePtr p_array;
    HogePtr* p_double;
    size_t cnt, cnt2;
    size_t size=10;

#if 0
    p_arry=init_calloc(size);
    if (!p_arry) {
	fprintf(stderr,"error: array allocation failed.\n");
	exit(1);
    } else {
	for (cnt=0; cnt<size; cnt++) {
	    printf("value ... %d\n", (p_arry[cnt])->x);
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
	    printf("line %u\n", cnt);
	    for (cnt2=0; cnt2<size; cnt2++) {
		//なにか実行。
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
