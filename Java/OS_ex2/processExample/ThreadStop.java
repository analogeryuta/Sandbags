package processExample;

/**
 * @author kono
 *
 */

public class ThreadStop extends Thread {
	public boolean start;

	SimpleThread t1;
	SimpleThread t2;
	SimpleThread t3;
	
	static public void main(String [] args) throws InterruptedException {
		ThreadStop self = new ThreadStop();
		self.start = true;
		self.start();
		self.init();
		self.sync();
	}
	
	public void init() throws InterruptedException {
		t1 = new SimpleThread("t1",-1,1,2,3);
		t2 = new SimpleThread("t2",-1,4,5,6);
		t3 = new SimpleThread("t3",-1,7,8,9);
   
		t1.start();
		t2.start();
		t3.start();
	}
	
	public synchronized void sync() throws InterruptedException {
		wait(120);
		t1.stop();
		t2.stop();
		t3.stop();
	}

}

