import java.io.*;
import java.lang.*;

public class SimpleThread implements Runnable {
    private volatile Thread blinker;
    private int interval=1000;
    private int currentCount=0;
    private int reserveCount=0;

    public SimpleThread() {
	//constructor
    }

    public void setReserveCount(int i) {
	reserveCount=i;
    }

    public boolean isMaxCount() {
	if (currentCount>=reserveCount) {
	    return true;
	} else {
	    return false;
	}
    }

    public void start() {
	System.out.println("call start()");
	blinker = new Thread(this);
	blinker.start();
    }

    public void stop() {
	System.out.println("call stop()");
	blinker = null;
    }

    public void run() {
	System.out.println("call run()");
	System.out.println("reserve count: " + reserveCount);
	Thread thisThread = Thread.currentThread();
	while (blinker == thisThread) {
	    try {
		//take interval
		thisThread.sleep(interval);
	    } catch(InterruptedException e) {
		//error handler
	    }
	    //do something below
	    if (this.isMaxCount()) {
		this.stop();
	    } else {
		System.out.println("runnning in main loop : count " + currentCount++);
	    }
	}
    }
}