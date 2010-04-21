package schedularSimulator;

import java.util.*;

public class Task {
	static int  task_count = 0;
	static int  task_clock = 0;
	static int  total_wait = 0;
	static int  total_turn_around = 0;


    int priority;
    int length;
    String name;
    int invoke;       /* invoke time of the task */
    int waiting;      /* total waiting time */
    int start;        /* first execution time */
    int end;          /* time of job end */
    int prev_end;     /* previous suspension time */
    char type;        /* n non-periodic, p periodic */
    int period;
    int next_time;
    int task_length;

	static void reset() {
		task_count = 0;
		task_clock = 0;
		total_wait = 0;
		total_turn_around = 0;
	}

	Task(String name_,int length_,int priority_) {
		name = name_;
		length = length_;
		priority = priority_;
	}
	
	Task(String name_,int length_,int priority_,int period_) {
		name = name_;
		task_length = length_;
		priority = priority_;
		length = 0;
		period = period_;
	}

	int exec_task(int quantum,Collection<Task>list)
	{
	    int exec_time;
	    if (quantum!=0 && quantum < length) {
	        length -= quantum;
	        exec_time = quantum;
	    } else {
	        exec_time = length;
	        length=0;
	    }
	    if (start == 0 ) { 
	        start = task_clock;
	        waiting = task_clock - invoke;
	    }
	    if (prev_end != 0) waiting += task_clock - prev_end;

	    task_clock += exec_time;

	    if (length == 0) {
	        end = task_clock;
	        total_wait += waiting;
	        total_turn_around += end - invoke;
	    } else {
	        prev_end = task_clock;
	    }

	    print_task(exec_time);
	    return exec_time;
	}

	void
	print_task(int exec_time)
	{
	    System.out.printf("%d\t%s: %d\n",task_clock-exec_time,name,exec_time);
	}

	void
	report_dead_line_miss()
	{
	    System.out.printf("%d\t%s: missed\n",task_clock,name);
	}

	static void	report()
	{
	    if (task_count==0) return;
	    System.out.printf("%d\tend:\n",task_clock);
	    System.out.printf("\naverage waiting time = %d\naverage turn around time = %d\n",
	      total_wait / task_count,
	      total_turn_around / task_count);
	}



}
