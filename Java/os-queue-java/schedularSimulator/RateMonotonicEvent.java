package schedularSimulator;

import java.util.PriorityQueue;

public class RateMonotonicEvent extends Event implements EventInterface {

    RateMonotonicEvent(int time_,PriorityQueue<Task> task_list_) {
    		task_list = task_list_;
    		time = time_;
    }
    
	public void exec(PriorityQueue<Event>event_list,int quantum) {
	    // task が優先度順に並んでいるとする
	    // 再投入を先にチェックして、一番短いquantumを見つける

	    for(Task q: task_list) {
	        if (q.type!='p') continue;
	        // もし、再投入時間ならば再投入する
	        if (q.next_time==PeriodicalRun.task_clock) {
	            q.next_time=PeriodicalRun.task_clock+q.period;
		    // 次の再投入イベントをスケジューリングする
	            event_list.add(new RateMonotonicEvent(q.next_time,task_list));
	            if (quantum==0 || quantum > q.period) quantum = q.period;
	            if (q.length>0) {
			// length が残っていると言うことは、
			// まだ、実行されてなかったということ
	                q.report_dead_line_miss();
	            }
	            q.length = q.task_length;  // タスクの再投入
	        }
	    }
	    for(Task q: task_list) {
	        if (q.type!='p') continue;
	        if (q.length>0) {
		    // まだ、実行されてないtaskで、
		    // 一番優先順位が高いものを実行する
		    //     task queue からは、取り除かない 
	            quantum -= q.exec_task(quantum,task_list);
	            if (quantum <= 0)
	                return;
	        }
	    }

	}
}
