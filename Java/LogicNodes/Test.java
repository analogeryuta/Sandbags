
public class Test {
	public static void main(String args[]) {
		int x;
		for(x=1; x<6; x++) {
			int y = 1;
			for(int j=0;j<x;j++) {
				y = y*x;
			}
			System.out.println(y + ":" + (y >= x));
		}
	}
}

