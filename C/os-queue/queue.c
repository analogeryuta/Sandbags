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

  Task Queue Manager

 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

const int QUEUE_MALLOC_ERROR =   10;

int queue_errno;

int
init_queue(int size)
{
    return 1;
}

void
destroy_queue()
{
}

QueuePtr
new_queue(char *name, int length, int priority)
{
    QueuePtr q;
    q = (QueuePtr) malloc(sizeof(Queue));
    if (!q) return q;
    q->next = NULL;
    q->priority = priority;
    q->name = name;
    q->length = length;
    q->invoke = 0;
    q->waiting = q->start = q->end = q->prev_end = 0;
    return q;
}

void
free_queue(QueuePtr q)
{
    free(q);
}

QueuePtr
insert_queue(QueuePtr list,QueuePtr q)
{
    q->next = list;
    return q;
}

QueuePtr
append_queue(QueuePtr list,QueuePtr q)
{
    QueuePtr p = list;
    if (!p) {
	return q;
    } else {
	while(p->next) p = p->next;
	p->next = q;
	return list;
    }
}

QueuePtr
dequeue(QueuePtr list,QueuePtr *q)
{
    QueuePtr p = list;
    if (p) {
        *q = list;
        p = list->next;
        list->next=0;
    }
    return p;
}

QueuePtr
remove_queue(QueuePtr list,QueuePtr q)
{
    QueuePtr p = list;
    QueuePtr p1;

    if (!p) return p;
    p1 = p->next;
    while(p1 && p1 != q) { p1 = p1->next; p = p->next; }
    if (p1) {
	p->next = p1->next;
    }
    return list;
}

QueuePtr
sort_queue(QueuePtr q,int (*comp)(QueuePtr,QueuePtr))
{
    QueuePtr top,high,low,r,r1;

    if (q == NULL) return q;
    if (q->next == NULL) return q;

    /* split list into high part and low part */
    high = low = NULL;
    for(r = q->next; r ; ) {
	r1 = r->next;
	if (comp(q,r)) {
	    r->next=high; high = r; 
	} else {
	    r->next=low; low = r; 
	}
	r = r1;
    }

    /* sort each parts */
    high = sort_queue(high,comp);
    low = sort_queue(low,comp);

    /* append sorted parts */
    q->next = low;
    if (high) {
	top = high;
	while(high->next) high = high->next;
	high->next = q;
    } else {
	return q;
    }

    return top;
}


/* end */
