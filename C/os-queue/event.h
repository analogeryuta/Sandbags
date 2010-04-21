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
