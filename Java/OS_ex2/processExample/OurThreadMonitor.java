package processExample;

public class OurThreadMonitor extends Thread {
	private int bufsize;
    private int buffer[];
    private int count, lo, hi; // counters and indices
    private String name;
    
    OurThreadMonitor(String _name,int _bufsize) {
    		name = _name;
    		bufsize = _bufsize;
    		buffer = new int[bufsize];
    }
    
    public synchronized void insert(int val) { 
        if (count == bufsize) go_to_sleep(); // if the buffer is full, go to sleep 
        buffer [hi] = val; // insert an item into the buffer 
        hi = (hi + 1) % bufsize; // slot to place next item in 
        count = count + 1; // one more item in the buffer now 
        if (count == 1) notify(); // if consumer was sleeping, wake it up 
    } 
    public synchronized int remove() { 
        int val; 
        if (count == 0) go_to_sleep( ); // if the buffer is empty, go to sleep 
        val = buffer [lo]; // fetch an item from the buffer 
        lo = (lo + 1) % bufsize; // slot to fetch next item from 
        count = count - 1 ; // one few items in the buffer 
        if (count == bufsize - 1) notify(); // if producer was sleeping, wake it up

        return val; 
    } 
    private void go_to_sleep() { 
    		try{
    			wait( );
    		} catch(InterruptedException exc) {
    			
    		};
    } 
}

