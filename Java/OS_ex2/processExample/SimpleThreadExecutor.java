package processExample;

import java.util.concurrent.*;

public class SimpleThreadExecutor {

    private final ExecutorService pool;

    public SimpleThreadExecutor(int poolSize) {
        pool = Executors.newFixedThreadPool(poolSize);
        // pool = Executors.newCachedThreadPool();
        // pool = new MyFixedExecutorService(poolSize);
    }
 

    public void serve(int numThread) {
        for (int i = 1;i<= numThread;i++) {
          pool.execute(new SimpleThreadHandler("thread"+i,2,i,1,2));
        }
    }
    
    public static void main(String args[]) {
    	int taskCount = 3;
    	SimpleThreadExecutor e = new SimpleThreadExecutor(10);
    	e.serve(taskCount);
    	e.pool.shutdown();
    	System.out.println("all done");
    }
}
