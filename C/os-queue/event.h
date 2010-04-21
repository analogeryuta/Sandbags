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

 Simple Event Driven Simulator 
   Event Structure

 */

typedef
struct event {
    struct event *next;
    int time;
    struct event *(*event)(struct event *task,QueuePtr *q,int quantum);
    QueuePtr *param;
} Event, *EventPtr;

extern int event_errno;

extern int init_event(int num);
extern void destory_event();
extern EventPtr new_event(int time, EventPtr event(),QueuePtr *param);

extern void free_event(EventPtr q);
extern EventPtr insert_event(EventPtr list,EventPtr q);
extern EventPtr insert_event1(EventPtr list,EventPtr q);
extern EventPtr append_event(EventPtr list,EventPtr q);
extern EventPtr remove_event(EventPtr list,EventPtr q);

extern EventPtr get_event(EventPtr list,EventPtr *q);
extern EventPtr sort_event(EventPtr q,int (*comp)());

/* end */
