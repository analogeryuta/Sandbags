/* hoge.h : �ƥ����ѹ�¤�Ρ�
 * int���ѿ����ؿ��ݥ��󥿡���¤�Υݥ���
 * ��3��Υ���
 */

typedef struct _hoge {
    int x;
    int y;
    /* int result;   //�黻���...��calc���֤��Τǥ��Ф��Ѱդ���ɬ�פʤ� */
    int (*calc)(struct _hoge *); //�黻��̤��֤��ؿ�
    struct _hoge *next;
} Hoge, *HogePtr;
