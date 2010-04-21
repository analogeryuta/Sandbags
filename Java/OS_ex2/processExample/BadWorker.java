package processExample;

public class BadWorker extends SimpleWorker {

	public BadWorker(String _name,int count_,SimpleWorker w) {
		String msg;
		name = _name; sharedResource = w;
		count = count_;
		msg = "Thread "+name+" created.";
		myResource = 0;
		System.out.println(msg);
	}
	
	public void run() {
		while(count < 0 || count-- > 0) {
			work();
		}
	}
	

	public synchronized void work() {
		int x;
		yield();
		x = 	sharedResource.getResource();
		yield();
		x = x + 1;
		yield();
		sharedResource.setResource(x);
		yield();
	}
}
