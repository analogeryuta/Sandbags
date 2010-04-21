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

  task executor

    requires "queue.h"

 */

extern int task_clock;
extern int task_count;

extern int exec_task(QueuePtr q,int quantum);
extern void print_task(QueuePtr q,int exec_time);
extern void die(char *err);
extern void report();
extern void report_dead_line_miss(QueuePtr q);

/* end */


