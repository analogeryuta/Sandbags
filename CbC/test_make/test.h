/* return, environment���������ѿ�������Ȥ��� 
 * extern��������ѿ��Ȥ������������Τ�����
 * �Ǥ���
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
