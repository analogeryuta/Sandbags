/*
  Separates a line by a space. separate() is defined in separate.c.

  cとcbcとのmodule linkについて調べるため. separate_sp.cはcで書いた。
  separate.cはcbcが使われており、separate()を定義する。
 */

#include<stdio.h>
#include<string.h>

#define MAX_WORD 100
#define BUF_SIZ 256

static char *w[MAX_WORD];

extern void separate(char** w, char *buf);

int
main()
{
    int i;
    const char *str = "hoge huga aho aho2";

    char buf[BUF_SIZ];
    char *p=buf;

    strncpy(buf, str, BUF_SIZ);

    separate(w, buf);

    for(i=0; w[i]!=NULL; i++) {
	printf("%s\n", w[i]);
    }
    return 0;
}

