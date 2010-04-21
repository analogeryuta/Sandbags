/*
  関数ポインタと構造体のテストその2．
  構造体で単方向リストを作成してみる.
  リスト中に関数ポインタをもたせ，間接gotoしてみる．
*/
#include <stdio.h>
#include <stdlib.h>

#define  NULL  ((void*)0)
#define  ELEMENT  8

code (*ret)();
void *env;

typedef struct functions{
    struct functions *next;
    code (*func)(struct functions *);
} Functions;

//Functions構造体で作るリストの先頭
Functions *head=NULL;
Functions *tail=NULL;

/*
  リストが持つ関数ポインタのgoto 先．
  てきとーでいいや．
*/
code 
hoge(Functions *f)
{
    printf("hoge\n");
    goto startExec(f);
}

code
fuga(Functions *f)
{
    printf("fuga\n");
    goto startExec(f);
}

//リストの作成．mallocの実行と，構造体の初期化を行う．
code
initList(int cnt)
{
    Functions *f;
    f = (Functions *)malloc(sizeof(Functions));

    if (cnt>0) {
	if (!head) {
	    head=f;
	    tail=f;
	    f->func = hoge;
	    f->next = NULL;
	} else {
	    tail->next=f;
	    tail=f;
	    f->func=fuga;
	    f->next=NULL;
	}
	goto initList(--cnt);
    }
    goto startExec(head);
}

/*
  リストに格納されている関数を順に実行
  リストをheadから辿っていくことになる．
*/
code 
startExec(Functions *h)
{
    Functions *tmp;
    tmp=h;

    if (tmp) {
	//リストを最後尾まで辿りつつ，func()実行
	tmp=tmp->next;
	goto h->func(tmp);
    }
    goto cleanList(head);
}

//構造体をfreeし，リストを消去する．
code
cleanList(Functions *h)
{
    Functions *tmp;
    tmp=h;

    if (h) {
	h=h->next;
	//free()の確認
	printf("free addr : %p\n",tmp);
	free(tmp);
	goto cleanList(h);
    }
    goto endExec();
}

//終了の合図．
code 
endExec()
{
    printf("finish\n");
    goto ret(0), env;
}

int
main()
{
    int element=ELEMENT;

    ret = return;
    env = environment;

    goto initList(element);
}
