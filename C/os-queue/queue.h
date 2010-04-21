/*
    OS Scheduler Simulator

** 連絡先： 琉球大学情報工学科 河野 真治  
** （E-Mail Address: kono@ie.u-ryukyu.ac.jp）
**
**    このソースのいかなる複写，改変，修正も許諾します。ただし、
**    その際には、誰が貢献したを示すこの部分を残すこと。
**    再配布や雑誌の付録などの問い合わせも必要ありません。
**    営利利用も上記に反しない範囲で許可します。
**    バイナリの配布の際にはversion messageを保存することを条件とします。
**    このプログラムについては特に何の保証もしない、悪しからず。
**
**    Everyone is permitted to do anything on this program 
**    including copying, modifying, improving,
**    as long as you don't try to pretend that you wrote it.
**    i.e., the above copyright notice has to appear in all copies.  
**    Binary distribution requires original version messages.
**    You don't have to ask before copying, redistribution or publishing.
**    THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE.

  Process Queue Structure
  
 */

typedef
struct queue {
    struct queue *next;
    int	priority;
    int length;
    char *name;
    int invoke;       /* invoke time of the task */
    int waiting;      /* total waiting time */
    int start;        /* first execution time */
    int end;          /* time of job end */
    int prev_end;     /* previous suspension time */
    int type;         /* n non-periodic, p periodic */
    int period;
    int next_time;
    int task_length;
} Queue, *QueuePtr;

extern int queue_errno;

extern int init_queue(int num);
extern void destory_queue();
extern QueuePtr new_queue(char *name, int length, int priority);
extern void free_queue(QueuePtr q);
extern QueuePtr insert_queue(QueuePtr list,QueuePtr q);
extern QueuePtr append_queue(QueuePtr list,QueuePtr q);
extern QueuePtr remove_queue(QueuePtr list,QueuePtr q);
extern QueuePtr dequeue(QueuePtr list,QueuePtr *q);
extern QueuePtr sort_queue(QueuePtr q,int (*comp)());

/* end */
