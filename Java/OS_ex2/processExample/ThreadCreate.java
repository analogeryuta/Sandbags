package processExample;

/**
 * @author kono
 *
 */

public class ThreadCreate extends Thread {

	static public void main(String [] args) throws InterruptedException {
		SimpleThread t1 = new SimpleThread("t1",2,1,2,3);
		SimpleThread t2 = new SimpleThread("t2",2,4,5,6);
		SimpleThread t3 = new SimpleThread("t3",2,7,8,9);
		
		t1.start();
		t2.start();
		t3.start();
	}
}