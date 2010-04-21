/*
    OS Scheduler Simulator

** Ϣ���衧 ΰ����ؾ��󹩳ز� ���� ����  
** ��E-Mail Address: kono@ie.u-ryukyu.ac.jp��
**
**    ���Υ������Τ����ʤ�ʣ�̡����ѡ�������������ޤ�����������
**    ���κݤˤϡ�ï���׸������򼨤�������ʬ��Ĥ����ȡ�
**    �����ۤ仨�����Ͽ�ʤɤ��䤤��碌��ɬ�פ���ޤ���
**    �������Ѥ�嵭��ȿ���ʤ��ϰϤǵ��Ĥ��ޤ���
**    �Х��ʥ�����ۤκݤˤ�version message����¸���뤳�Ȥ���Ȥ��ޤ���
**    ���Υץ����ˤĤ��Ƥ��ä˲����ݾڤ⤷�ʤ����������餺��
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
