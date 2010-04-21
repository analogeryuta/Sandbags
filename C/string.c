/*
  文字列の扱いに関するテスト．
  いろいろ解からないことだらけだ．
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char*
create_str_val(char *str)
{
    char *s;
    int len;

    len = strlen(str);
    if (len!=0) {
	s = (char *)malloc(len);
	strcpy(s, str);
    } else {
	return EXIT_FAILURE;
    }
    return s;
}

int
main()
{
    int i;
    //char型配列，ポインタ各変数の利用
    char str1[256] = "hogehogefuga";
    char *str2 = "hogehogefugafuga";

    char str3[3][256] = {"hoge","fuga","abeshi"};
    char *str4[] = {"uge", "bubera", "hebushi"};

    printf("%s\n", str1);
    printf("%s\n", str2);
    for (i=0; i<3; i++) {
	printf("%s\n", str3[i]);
	printf("%s\n", str4[i]);
    }

    return 0;
}
