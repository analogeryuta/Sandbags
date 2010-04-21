package processExample;

public class SimpleWorker extends Thread {
	String name;
	int count;
	int myResource;
	SimpleWorker sharedResource;
	
	SimpleWorker() {
		// empty
	}
	
	public SimpleWorker(String _name,int count_,SimpleWorker w) {
		String msg;
		name = _name; sharedResource = w;
		count = count_;
		msg = "Thread "+name+" created.";
		myResource = 0;
		System.out.println(msg);
	}
	
	public void run() {
		while(count < 0 || count-- > 0) {
			sharedResource.work();
		}
	}

	public void work() {
		int x;
		yield();
		x = 	myResource;
		yield();
		x = x + 1;
		yield();
		myResource = x;
		yield();
	}
	
	public void setResource(int x) {
		myResource = x;
	}
	
	public int getResource() {
		return myResource;
	}
	
}
