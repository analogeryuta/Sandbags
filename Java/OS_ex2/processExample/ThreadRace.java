package processExample;

public class ThreadRace {
	
	static public void main(String [] args) throws InterruptedException {
	
		SimpleWorker t1 = new SimpleWorker("t1",-1,null); // does not run
		SimpleWorker t2 = new SimpleWorker("t2",5,t1);
		SimpleWorker t3 = new SimpleWorker("t3",5,t1);
   
		t2.start();
		t3.start();
		t2.join(0);
		t3.join(0);

		String msg = "Thread t1 "+Integer.toString(t1.getResource());
		System.out.println(msg);
		
	}

}
