/* interface.c : 
 *   code segmentの引数(interface)を構造体で定義するテスト．
 *   ...(悪い例の)スケジューラっぽいやつの試作品？
 *   関数ポインタ(間接 goto)の扱い方を間違ってる気がする．
 *   絶対間違ってる．．．
 */
#include <stdio.h>
#define   NULL  ((void*)0)

//code (*ret)();
//void *env;

typedef struct hoge {
    code (*next)(struct hoge);
    int hop_cnt;
    code (*ret)();
    void *env;
} Hoge;

//プロトタイプ宣言．
static code function1_1(Hoge );
static code function1_2(Hoge );
static code function2_1(Hoge );
static code function2_2(Hoge );

int
main(int argc, char *argv[])
{
    Hoge i;

    i.next = function1_1;
    i.hop_cnt = 0;
    i.ret = return;
    i.env = environment;

    printf("main :: execute func ptr : %p\n", i.next);

    goto func_start(i);
}


static code 
function1_1(Hoge arg)
{
    arg.next = function1_2;
    printf("Hop Count : %d\n", ++arg.hop_cnt);
    goto func_start(arg);
}

static code 
function1_2(Hoge arg)
{
    arg.next = function2_1;
    printf("Hop Count : %d\n", ++arg.hop_cnt);
    goto func_start(arg);
}

static code 
function2_1(Hoge arg)
{
    arg.next = function2_2;
    printf("Hop Count : %d\n", ++arg.hop_cnt);
    goto func_start(arg);
}

static code
function2_2(Hoge arg)
{
    arg.next = NULL;
    printf("Hop Count : %d\n", ++arg.hop_cnt);
    goto func_start(arg);
}

static code 
func_start(Hoge arg)
{
    //goto 先をif文で判定．
    //これ関数ポインタの使いかた,絶対間違ってると思う．
    code (*func)(Hoge );

    printf("next execute func ptr : %p\n", arg.next);

    if (arg.next==function1_1) {
	func = arg.next;
	arg.next = function1_2;
	goto func(arg);
    } else if (arg.next==function1_2) {
	func = arg.next;
	arg.next = function2_1;
	goto func(arg);
    } else if (arg.next==function2_1) {
	func = arg.next;
	arg.next = function2_2;
	goto func(arg);
    } else if (arg.next==function2_2) {
	func = arg.next;
	arg.next = function1_2;
	goto func(arg);
    } else if (arg.next==NULL) {
	printf("Finish.\n");
	goto arg.ret(0), arg.env;
    }

    //条件判定のいずれにも引っかからなかった場合
    printf("Error.\n");
    goto arg.ret(0), arg.env;
}
