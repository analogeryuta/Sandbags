/*
  ファイルの読み込み(fopen, fclose, fgetsとか)の練習
  読み込んだファイルから数値をよみこみ，構造体リストへ
  格納する．

  構造体リストのデータから，標準出力に"*"を出力する．
  出力パターンの位置は構造体メンバの x, yにしたがう．
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  BUFF_SIZE    256

//構造体リスト．ファイルから読んだデータを持っておく．
typedef struct container {
    int x;
    int y;
    char opt_str[BUFF_SIZE];
    struct container *next;
} InfoContainer, *InfoContainerPtr;


FILE*
open_file(char *file)
{
    FILE *fp;
    if (!(fp=fopen(file, "r"))) {
	fprintf(stderr, "error : read file : %s\n", file);
	exit(EXIT_FAILURE);
    }
    return fp;
}

void
close_file(FILE *fp)
{
    fclose(fp);
}

InfoContainerPtr
create_container(int x, int y, char *str)
{
    InfoContainerPtr i;
    i = (InfoContainerPtr )malloc(sizeof(InfoContainer));

    if (i) {
	i->x = x;
	i->y = y;
	//i->opt_str = str;
	strncpy(i->opt_str, str, strlen(str));
	i->next = NULL;
    } else {
	fprintf(stderr, "error : malloc()\n");
	exit(EXIT_FAILURE);
    }
    return i;
}

/*
  構造体同士を繋げる．
  繋げて出来たリストの先頭要素へのポインタを返す
*/
InfoContainerPtr
connect_container(InfoContainerPtr head, InfoContainerPtr new)
{
    InfoContainerPtr tmp;
    tmp = head;

    while (tmp->next) {
	tmp = tmp->next;
    }
    tmp->next = new;
    return head;
}

/*
  構造体ポインタが指す領域に,ファイルからよんだデータを
  書き込み，リストを作る．
  作成した構造体リストの先頭へのポインタを返す．
*/
InfoContainerPtr
create_list(FILE *fp)
{
    char *buf_ptr, buf[BUFF_SIZE]; //fgets()の戻り値, バッファ
    char *str;                     //文字列．構造体のメンバ．
    int x, y;                      //数値．構造体のメンバ．
    InfoContainerPtr head = NULL;  //作成するリストの先頭
    InfoContainerPtr src;          //作業用変数
   
    while ((buf_ptr=fgets(buf, sizeof(buf), fp))!=NULL) {
	//'#'が先頭にある行は,以下の処理をスキップする．
	if (buf[0]=='#') {
	    continue;
	} else {
	    sscanf(buf_ptr, "%d %d %s\n", &x, &y, str);
	    src = create_container(x, y, str);
	    //headにあたる構造体がない場合，それを生成．
	    if (head) {
		head = connect_container(head, src);
	    } else {
		head = connect_container(src, NULL);
	    }
	}
    }
    return head;
}

/*
  作成したリストを辿り,保持するデータを出力する．
*/
void
print_data(InfoContainerPtr head)
{
    fprintf(stdout,"x:%2d, y:%2d, opt_str:%s\n", 
	    head->x, 
	    head->y, 
	    head->opt_str);
    if (head->next) {
	print_data(head->next);
    }
}

/*
  x, yを座標にみたて，"#"を画面に出力する．
  表示方法は以下のようなイメージで．
====================================
 |1 2 3 4 5 6 7 8  X軸
- - - - - - - - - ->
1|_|_|_|*|_|_|_|_|
2|_|_|*|_|*|_|_|_|
3|_|_|*|*|*|*|_|_|
4|_|_|*|*|*|_|_|_|
 |
 Y軸
====================================
x軸方向にのびる1列のパターンを，y軸方向に連続して
表示させていく．

viewに相当する部分なので，InfoContainerには
直接影響を及ぼさない(ようにする)．
*/
void
print_pattern(InfoContainerPtr head)
{
    char *spce = " ";  //タイルのない空白部分
    char *tile = "#";  //タイル

    InfoContainerPtr i = NULL;
    int tmp_x = 0;
    int tmp_y = 0;
    int spce_cnt = 0;

    for (i=head; i!=NULL; i=i->next) {

	if (tmp_y>0 && (tmp_y != i->y)) {
	    tmp_x = 0;
	    fprintf(stdout,"\n");
	}
	
	spce_cnt = (i->x - tmp_x) - 1;	//空白の個数を調べる
	while (spce_cnt>0) {            //空白の出力
	    fprintf(stdout,"%s",spce);
	    spce_cnt--;
	}
	fprintf(stdout,"%s", tile); //タイル1個を出力

	tmp_x = i->x;
	tmp_y = i->y;
    }
    fprintf(stdout,"\n");
}

int
main(int argc, char *argv[])
{
    FILE *fp;
    InfoContainerPtr head;

    if (argc != 2) {
	fprintf(stderr, "Usage : %s [file_name]\n", argv[0]);
	return EXIT_FAILURE;
    } else {
	//open_file() 〜 close_file()まで, initにあたる処理
	fp = open_file(argv[1]);
	head = create_list(fp);
	close_file(fp);

	//以下，実際の出力を行う処理．
	print_pattern(head);
    }
    return 0;
}
