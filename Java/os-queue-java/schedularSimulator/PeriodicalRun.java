package schedularSimulator;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;



public class PeriodicalRun {

	int quantum = 0;
	static final int BUFSIZ = 4096;
	int task_count;
	static int task_clock = 0;
	static final int limit = 400;


	/*
	   標準入力から与えられたタスクのデータを読み込み、
	   task のqueue を作成して、 run で実行する。

	    # type[n/p] clock taskname task-size priority [period]
	    n 0 a 110 5

	    n non-periodic
	    p periodic
	 */
	public static void
	main(String []args) throws FileNotFoundException
	{
		PeriodicalRun self = new PeriodicalRun();
		self.task_init(args);
		
	}
	
	/*
	   task の sort 用の関数
	 */
	class by_period implements Comparator<Task> {
	
		public int compare(Task q,Task r)
		{
			return q.period==r.period?0:q.period > r.period?1:-1;
		}
	}
	
	/*
	   event の sort 用の関数
	 */
	class by_time implements Comparator<Event> {
	
		public int compare(Event q,Event r)
		{
			return q.time==r.time?0:q.time > r.time?1:-1;
		}
	}


	
	public void task_init(String [] args) throws FileNotFoundException
	{
	    int time; String name; int length; int priority; 
	    int period;
		Comparator<Task> comp = new by_period();
		PriorityQueue<Task> task_list = new PriorityQueue<Task>(1024,comp) ;
		Comparator<Event> comp1 = new by_time();
		PriorityQueue<Event> event_list = new PriorityQueue<Event>(1024,comp1) ;
	    Task q;
	    char type;

		File from = new File(args[0]);
	    Scanner scanner = new Scanner(from);
	    scanner.useDelimiter("\\s+");
	    
	    task_count = 0;

	    while(scanner.hasNext()) {
	    		try {
	    	    char top = scanner.next().charAt(0); 
	        if (top=='#'||top!='p') {
	        		scanner.nextLine();
	        		continue;
	    		}
	        type = 'p'; // scanner.next().charAt(0); System.out.println("type= "+type);
	        time = scanner.nextInt();         // System.out.println("time= "+time);
	        name = scanner.next();            // System.out.println("name= "+name);
	        length = scanner.nextInt();       // System.out.println("length= "+length);
	        priority = scanner.nextInt();     // System.out.println("priority= "+priority);
	        period = scanner.nextInt();       // System.out.println("period= "+period);
	        q = new Task(name, length, priority, period);
	        q.type = type;
	        task_list.add(q);
	        task_count++;
	    		} catch ( java.util.InputMismatchException e) {
	    			System.out.print("task list syntax error on ");
	        		System.out.println(
	        				scanner.nextLine()); continue; 
	    		}
	    		scanner.nextLine();
	    } 
	    
	    event_list.add(new RateMonotonicEvent(0,task_list));
	    run(event_list);
	    Task.report();
	}

	void
	run(PriorityQueue<Event> event_list)
	{
		while(!event_list.isEmpty()) {
			Event event = event_list.poll();
			task_clock = event.time;
	        if (limit >0 && task_clock>limit) {
	            break;
	        }
	        Event next =event_list.peek();
	        int quantum = (next==null)?0:next.time-task_clock;
	        event.exec(event_list,quantum);
		}
	}

}
