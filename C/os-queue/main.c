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

   Queue based scheduler

 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "queue.h"
#include "task.h"

static void run(QueuePtr task);
void fifo(QueuePtr task);
void sjf(QueuePtr task);

static char buf[BUFSIZ];

static int quantum = 0;

/*
   標準入力から与えられたタスクのデータを読み込み、
   task のqueue を作成して、 run で実行する。

    # type[n/p] clock taskname task-size priority [period]
    n 0 a 110 5

    n non-periodic
    p periodic
 */
int
main()
{
    int time; char name[BUFSIZ]; int length; int priority;
    QueuePtr task_list = NULL;
    QueuePtr q;
    char *name1;
    char type;

    init_queue(100);

    task_count = 0;
    while(fgets(buf,BUFSIZ,stdin)!=NULL) {
	if (buf[0]=='#') continue;
	if (buf[0]!='n') continue;
	sscanf(buf,"%c %d %s %d %d",&type,&time,name,&length,&priority);
	if ((name1=malloc(strlen(name)))==0) {
	    die("Can't allocate name\n");
	}
	strcpy(name1,name);
	q = new_queue(name1, length, priority);
	if (!q) {
	    die("Can't allocate queue\n");
	}
	task_list = append_queue(task_list,q);
	task_count++;
    }
    run(task_list);
    report();
    return 0;
}

static void
run(QueuePtr task)
{
    // fifo(task);
    sjf(task);
}


/*
    First in First Out で実行する
 */

void
fifo(QueuePtr task)
{
    QueuePtr q;
    while(task) {
	task = dequeue(task,&q);
	exec_task(q,quantum);
    }
}

/*
   task の sort 用の関数
 */

static 
int by_length(QueuePtr q,QueuePtr r)
{
    return q->length > r->length;
}

/*
    Shoftest Job First で実行する
 */

void
sjf(QueuePtr task)
{
    QueuePtr q;
    task  = sort_queue(task,by_length);
    while(task) {
	task = dequeue(task,&q);
	exec_task(q,quantum);
    }
}


/* end */
