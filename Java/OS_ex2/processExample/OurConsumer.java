package processExample;

public class OurConsumer extends Thread {

	OurThreadMonitor mon;
	String name;
	
	OurConsumer(String name_, OurThreadMonitor mon_) {
		mon = mon_;
		name = name_;
	}
    public void run() { // run method contains the thread code 
        int item; 
        while (true) { // consumer loop 
            item = mon.remove(); 
            consume_item (item); 
        } 
    }
    private void consume_item(int item) {
    		String msg = "Consumer "+name+" eats "+Integer.toString(item);
    		System.out.println(msg);
    	
    } // actually consume 

}
