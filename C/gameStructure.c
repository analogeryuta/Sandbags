/*ゲームプログラムの基本的な記述例(while, ifとかの書き方)
 *をかんがえてみた．
 */
#include <stdio.h>
#include <stdlib.h>

/*
  TRUE, FALSEは必要でしょ?
*/
typedef enum {
    FALSE,
    TRUE
} Bool;

/*
  ゲームの状態管理(start, exec, finishとか)を行う
 */
typedef enum {
    START,
    MAIN,
    FINISH
} State;

/*
  表示するオブジェクトの情報を示す構造体
  malloc() は必須, なのでポインタ型も必ず作っておこう．
 */
typedef struct object {
    struct object *next;
    struct object *prev;
    OBJECT *obj;
    int obj_id;
} Object, *ObjectPtr;

/*
  ゲームオブジェクトを管理する構造体.
  スケジュール管理もさせるの?
*/
typedef struct game {
    State state;
    Object game_obj;
} Game, GamePtr;


/* Init() -> Setup() -> Exec() -> StateCheck() -> Finish()
 * くらいの手順か?
 */
int
main(int argc, char *argv[])
{
    Bool continueFlg=TRUE;
    Game g;

    Init(g);

    //ここのwhileループの書き方が基本．
    while (continueFlg==TRUE) {
	Setup();
	continueflg=StateCheck(g.state);
	Exec(g);
	Clear();
    }
    Finish(g);

    return 0;
}
