/* hoge.h : テスト用構造体。
 * int型変数、関数ポインタ、構造体ポインタ
 * の3種のメンバ
 */

typedef struct _hoge {
    int x;
    int y;
    /* int result;   //演算結果...はcalcで返すのでメンバを用意する必要なし */
    int (*calc)(struct _hoge *); //演算結果を返す関数
    struct _hoge *next;
} Hoge, *HogePtr;
