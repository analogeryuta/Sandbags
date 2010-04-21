package processExample;

public class ThreadProdCons {

		
	static public void main(String [] args) throws InterruptedException {
		OurThreadMonitor monitor = new OurThreadMonitor("m1",5);
		Thread p1 = new OurProducer("p1",10,monitor);
		Thread c1 = new OurConsumer("c1",monitor);
		
		monitor.start();
		p1.start();
		c1.start();
		p1.join();
		
		c1.stop();
		monitor.stop();
	}
}
