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
  Event Management

 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "event.h"

const int EVENT_MALLOC_ERROR =   10;

int event_errno;

int
init_event(int size)
{
    return 1;
}

void
destroy_event()
{
}

EventPtr
new_event(int time, EventPtr event(),QueuePtr *param)
{
    EventPtr q;
    q = (EventPtr) malloc(sizeof(Event));
    if (!q) return q;
    q->next = NULL;
    q->time = time;
    q->event = event;
    q->param = param;
    return q;
}

void
free_event(EventPtr q)
{
    free(q);
}


EventPtr
insert_event(EventPtr list,EventPtr q)
{
    EventPtr p = list;
    int time = q->time;
    if (!p) {
	return q;
    } 
    if (p->time > time) {
	q->next = p; return q;
    }
    if (!p->next) {
	p->next = q; return p;
    } 
    while(p->next && p->next->time < time) {
	p = p->next;
    }
    q->next = p->next;
    p->next = q;
    return list;
}

/*  
   Insert one event, one event at a time.
   Duplicate event is freed.
 */

EventPtr
insert_event1(EventPtr list,EventPtr q)
{
    EventPtr p = list;
    int time = q->time;
    if (!p) {
	return q;
    } 
    if (p->time > time) {
	q->next = p; return q;
    } else if (p->time == time) {
	free_event(q);
	return list;
    }
    if (!p->next) {
	p->next = q; return p;
    } 
    while(p->next && p->next->time <= time) {
	if (p->next->time == time) {
	    free_event(q);
	    return list;
	}
	p = p->next;
    }
    q->next = p->next;
    p->next = q;
    return list;
}


EventPtr
get_event(EventPtr list,EventPtr *q)
{
    EventPtr p = list;
    if (p) {
	*q = list;
	return list->next;
    }
    return p;
}

EventPtr
remove_event(EventPtr list,EventPtr q)
{
    EventPtr p = list;
    EventPtr p1;

    if (!p) return p;
    p1 = p->next;
    while(p1 && p1 != q) { p1 = p1->next; p = p->next; }
    if (p1) {
	p->next = p1->next;
    }
    return list;
}


/* end */
