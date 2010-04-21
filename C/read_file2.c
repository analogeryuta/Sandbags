/*
  ファイルの読み込み(fopen, fclose, fgetsとか)の練習
  読み込んだファイルから数値をよみこみ，構造体リストへ
  格納する．
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
    char *str;  //文字列．構造体のメンバ．
    int x, y;   //数値．  構造体のメンバ．
    InfoContainerPtr head = NULL;  //作成するリストの先頭
    InfoContainerPtr src;        //作業用変数
   
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

int
main(int argc, char *argv[])
{
    FILE *fp;
    InfoContainerPtr head;

    if (argc != 2) {
	fprintf(stderr, "Usage : %s [file_name]\n", argv[0]);
	return EXIT_FAILURE;
    } else {
	fp = open_file(argv[1]);
	head = create_list(fp);
	close_file(fp);
	print_data(head);
    }
    return 0;
}
