package processExample;

import java.util.Collection;
import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

public class MyExecutorService implements ExecutorService {

	private LinkedList<Thread> threadQueue;

	public MyExecutorService() {
		threadQueue = new LinkedList<Thread>();
	}
	
	public boolean awaitTermination(long timeout, TimeUnit unit)
			throws InterruptedException {
		shutdown();
		return true;
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
		// TODO Auto-generated method stub
		return isTerminated();
	}

	public synchronized boolean isTerminated() {
		// TODO Auto-generated method stub
		return threadQueue.isEmpty();
	}

	public synchronized void shutdown() {
		for(Thread t:threadQueue) {
			try {
				t.join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		threadQueue.clear();
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

	public synchronized void execute(Runnable r) {
		Thread t = new Thread(r);
		threadQueue.add(t);
		t.start();
	}

}
