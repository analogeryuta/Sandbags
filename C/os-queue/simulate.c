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

 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "queue.h"
#include "event.h"
#include "task.h"

static int by_period(QueuePtr q,QueuePtr r);

static char buf[BUFSIZ];

static EventPtr rate_monotonic(EventPtr task,QueuePtr *queue_ptr,int quantum);
static void simulate(EventPtr task,int limit);
static int get_quantum(EventPtr list);

static int limit = 400;

int
main()
{
    int time; char name[BUFSIZ]; int length; int priority;
    EventPtr task_list = NULL;
    QueuePtr q,queue;
    char *name1;
    char type;
    int period;

    init_queue(100);
    init_event(100);

    task_count = 0;
    while(fgets(buf,BUFSIZ,stdin)!=NULL) {
        if (buf[0]=='#') continue;
        if (buf[0]!='p') continue;
        sscanf(buf,"%c %d %s %d %d %d",
	    &type,&time,name,&length,&priority,&period);
        if ((name1=malloc(strlen(name)))==0) {
            die("Can't allocate name\n");
        }
        strcpy(name1,name);
        q = new_queue(name1, length, priority);
        if (!q) {
            die("Can't allocate queue\n");
        }
	q->type = type;
	q->period = period;
	q->task_length = length;
	q->length = 0; /* not missed at first time */
        queue = append_queue(queue,q);
        task_count++;
    }
    queue = sort_queue(queue,by_period);
    task_list = new_event(0, rate_monotonic, &queue);
    if (!task_list) {
	die("Can't allocate task\n");
    }
    simulate(task_list,limit);
    printf("%d\tend:\n",task_clock);
    return 0;
}


static void
simulate(EventPtr task,int limit)
{
    EventPtr e;
    int quantum;

    while(task) {
	task=get_event(task,&e);
	task_clock = e->time;
	if (limit && task_clock>limit) {
	    break;
	}
	quantum = get_quantum(task);
	task = e->event(task,e->param,quantum);
	free_event(e);
    }
}

int
get_quantum(EventPtr list)
{
    if (!list) {
        return 0;
    } else {
        return list->time - task_clock;
    }
}

static EventPtr
rate_monotonic(EventPtr task,QueuePtr *queue_ptr,int quantum)
{
    QueuePtr q;

    // task が優先度順に並んでいるとする
    // 再投入を先にチェックして、一番短いquantumを見つける

    for(q= *queue_ptr;q;q=q->next) {
	if (q->type!='p') continue;
	// もし、再投入時間ならば再投入する
	if (q->next_time==task_clock) {
	    q->next_time=task_clock+q->period;
	    task = insert_event1(task,
		new_event(q->next_time, rate_monotonic, queue_ptr));
	    if (quantum==0 || quantum > q->period) quantum = q->period;
	    if (q->length>0) {
		report_dead_line_miss(q);
	    }
	    q->length = q->task_length;
	}
    }
    for(q= *queue_ptr;q;q=q->next) {
	if (q->type!='p') continue;
	// 一番優先順位が高いものを実行する
	if (q->length) {
	    quantum -= exec_task(q,quantum);
	    if (quantum <= 0)
		return task;
	}
    }
    /* other task (may be non-periodic one ) */
    return task;
}

static int by_period(QueuePtr q,QueuePtr r)
{
    return q->period > r->period;
}


/* end */
