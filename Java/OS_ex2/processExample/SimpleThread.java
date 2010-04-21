package processExample;

public class SimpleThread extends Thread {
	String name;
	int count;
	int a;
	int b;
	int c;
	public SimpleThread(String _name,int count_,int a_,int b_,int c_) {
		String msg;
		name = _name; a = a_; b = b_; c = c_;
		count = count_;
		msg = "Thread "+name+" created.";
		System.out.println(msg);
	}
	
	public void run() {
		while(count < 0 || count-- > 0) {
			String msg = "Thread "+name+" "+Integer.toString(a)+" "+Integer.toString(b)
				+" "+Integer.toString(c);
			System.out.println(msg);
		}
	}
}
