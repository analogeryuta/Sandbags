package schedularSimulator;

import java.util.PriorityQueue;

public class Event implements EventInterface {
    public int time;
    public PriorityQueue<Task> task_list;

    Event() {
    	
    }

    Event(int time_,PriorityQueue<Task> task_list_) {
    		task_list = task_list_;
    		time = time_;
    }
    
	public void exec(PriorityQueue<Event>event_list,int quantum) {
		
	}
        
}
