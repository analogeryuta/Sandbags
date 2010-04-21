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

 Task Executor and Reporter

 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "queue.h"
#include "task.h"

int	task_count;
int	task_clock = 0;

static int	total_wait;
static int	total_turn_around;

int
exec_task(QueuePtr q,int quantum)
{
    int exec_time;
    if (quantum && quantum < q->length) {
	q->length -= quantum;
	exec_time = quantum;
    } else {
	exec_time = q->length;
	q->length=0;
    }
    if (q->start == 0 ) { 
	q->start = task_clock;
	q->waiting = task_clock - q->invoke;
    }
    if (q->prev_end != 0) q->waiting += task_clock - q->prev_end;

    task_clock += exec_time;

    if (q->length == 0) {
	q->end = task_clock;
	total_wait += q->waiting;
	total_turn_around += q->end - q->invoke;
    } else {
	q->prev_end = task_clock;
    }

    print_task(q,exec_time);
    return exec_time;
}

void
print_task(QueuePtr q,int exec_time)
{
    printf("%d\t%s: %d\n",task_clock-exec_time,q->name,exec_time);
}

void
report_dead_line_miss(QueuePtr q)
{
    printf("%d\t%s: missed\n",task_clock,q->name);
}

void
report()
{
    if (task_count==0) return;
    printf("%d\tend:\n",task_clock);
    printf("\naverage waiting time = %d\naverage turn around time = %d\n",
      total_wait / task_count,
      total_turn_around / task_count);
}

void
die(char *err)
{
    fprintf(stderr,"%s\n",err);
    exit(1);
}

/* end */
