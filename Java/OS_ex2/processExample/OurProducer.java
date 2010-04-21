package processExample;

public class OurProducer extends Thread {
	OurThreadMonitor mon;
	String name;
	int counter;
	
	OurProducer(String name_,int counter_, OurThreadMonitor mon_) {
		mon = mon_;
		name = name_;
		counter = counter_;
	}
	
    public void run() { // run method contains the thread code 
        int item; 
        while (counter>=0) { // producer loop 
            item = produce_item(); 
            mon.insert(item); 
        } 
    } 
    private int produce_item() {  return counter--; } // actually produce 


}
