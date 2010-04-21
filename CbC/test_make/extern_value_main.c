/* extern_value_main.c : 
 *    makefile記述, ファイル分割, externによる
 *    外部変数の参照とか，いろいろ．
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

code (*ret)(int);
void *env;

/*** extern_value1.c  ***/
extern code Setup(int );

int
main(int argc, char *argv[])
{
    ret = return;
    void = environment;
    
    goto Setup(5, NULL);
}
