package schedularSimulator;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Run {
	static int quantum = 0;
	static final int BUFSIZ = 4096;
	static int task_count;

	/*
	   標準入力から与えられたタスクのデータを読み込み、
	   task のqueue を作成して、 run で実行する。

	    # type[n/p] clock taskname task-size priority [period]
	    n 0 a 110 5

	    n non-periodic
	    p periodic
	 */
	public static void
	main(String args[]) throws FileNotFoundException
	{
		Run self = new Run();
		self.task_init(args);
	}
	
	public void task_init(String args[]) throws FileNotFoundException 
	{
	    int time; String name; int length; int priority;
	    LinkedList<Task> task_list = new LinkedList<Task>() ;
	    Task q;
	    char type;

		File from = new File(args[0]);
	    Scanner scanner = new Scanner(from);
	    scanner.useDelimiter("\\s+");
	    
	    task_count = 0;
	    
	    while(scanner.hasNext()) {
	    		try {
	    		char top = scanner.next().charAt(0); 
	        if (top=='#'||top!='n') {
	        		scanner.nextLine();
	        		continue;
	    		}
	        			        
	        type = 'n'; // scanner.next().charAt(0); System.out.println("type= "+type);
	        time = scanner.nextInt();        // System.out.println("time= "+time);
	        name = scanner.next();           // System.out.println("name= "+name);
	        length = scanner.nextInt();      // System.out.println("length= "+length);
	        priority = scanner.nextInt();    // System.out.println("priority= "+priority);
	        q = new Task(name, length, priority);
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
	    run(task_list);
	    Task.report();
	}

	void
	run(LinkedList<Task> task_list)
	{
	    // fifo(task_list);
	    sjf(task_list);
	}


	/*
	    First in First Out で実行する
	 */

	void
	fifo(LinkedList<Task> task_list)
	{
	    while (! task_list.isEmpty()) {
	    		Task q = task_list.poll();
	        q.exec_task(quantum,task_list);
	    }
	}

	/*
	   task の sort 用の関数
	 */
	class by_length implements Comparator<Task> {
	
		public int compare(Task q,Task r)
		{
			return q.length==r.length?0:q.length > r.length?1:-1;
		}
	}

	/*
	    Shortest Job First で実行する
	 */

	void
	sjf(LinkedList<Task> task_list)
	{
		Comparator<Task> comp = new by_length();
	    PriorityQueue<Task> list = new PriorityQueue<Task>(1024,comp);
	    for (Task q: task_list) {
	    		list.add(q);
	    }
	    while (!list.isEmpty()) {
    			Task q = list.poll();
	    		q.exec_task(quantum,list);
	    }
	}



}
