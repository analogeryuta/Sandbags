package processExample;

public class SimpleThreadHandler implements Runnable {


		String name;
		String msg;
		int count;
		int a;
		int b;
		int c;
		
		public SimpleThreadHandler(String _name,int count_,int a_,int b_,int c_) {
			name = _name; a = a_; b = b_; c = c_;
			count = count_;
			msg = name+ " "+a +" "+ b	+" "+c+" ";
			
			System.out.println(msg+" created.");
		}
		
		public void run() {
			while(count < 0 || count-- > 0) {
				System.out.println(msg+count);
			}
		}
}
