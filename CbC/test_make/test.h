/* return, environmentを受け取る変数の宣言とか， 
 * extern宣言した変数とかを定義したものだす．
 * です．
 */
#define  NULL  ((void*)0)

extern code (*ret)(int);
extern void *env;

typedef int iArray[4];
//typedef int (*iArrayPtr)[4];

typedef struct test {
    code (*func)();
    int id;
    char *str;
    struct test *next;
} Test, TestPtr;

extern TestPtr ListHead;
