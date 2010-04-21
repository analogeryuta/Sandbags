package processExample;

import java.util.Collection;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

public class MyFixedExecutorService implements ExecutorService {

	private Thread threadArray[];
	private int numTask;
	private int poolSize;
	
	public MyFixedExecutorService(int poolSize) {
		this.threadArray = new Thread[poolSize];
		this.poolSize = poolSize;
		this.numTask = 0;
	}

	public boolean awaitTermination(long timeout, TimeUnit unit)
			throws InterruptedException {
		// TODO Auto-generated method stub
		return false;
	}

	public <T> List<Future<T>> invokeAll(Collection<Callable<T>> tasks)
			throws InterruptedException {
		// TODO Auto-generated method stub
		return null;
	}

	public <T> List<Future<T>> invokeAll(Collection<Callable<T>> tasks,
			long timeout, TimeUnit unit) throws InterruptedException {
		// TODO Auto-generated method stub
		return null;
	}

	public <T> T invokeAny(Collection<Callable<T>> tasks)
			throws InterruptedException, ExecutionException {
		// TODO Auto-generated method stub
		return null;
	}

	public <T> T invokeAny(Collection<Callable<T>> tasks, long timeout,
			TimeUnit unit) throws InterruptedException, ExecutionException,
			TimeoutException {
		// TODO Auto-generated method stub
		return null;
	}

	public boolean isShutdown() {
		shutdown();
		return true;
	}

	public synchronized boolean isTerminated() {
		return threadArray == null;
	}

	public synchronized void shutdown() {
			try {
				for(int i=0;i<numTask;i++) {
					threadArray[i].join();
				}
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			threadArray = null;
	}


	public List<Runnable> shutdownNow() {
		shutdown();
		return null;
	}

	public <T> Future<T> submit(Callable<T> task) {
		// TODO Auto-generated method stub
		return null;
	}

	public Future<?> submit(Runnable task) {
		// TODO Auto-generated method stub
		return null;
	}

	public <T> Future<T> submit(Runnable task, T result) {
		// TODO Auto-generated method stub
		return null;
	}

	public synchronized void execute(Runnable command) {
		if (numTask<poolSize) {
			(threadArray[numTask++] = new Thread(command)).start();
		}

	}

}
