package schedularSimulator;

import java.util.*;

public interface EventInterface {
	void exec(PriorityQueue<Event>event_list,int quantum); 
}
