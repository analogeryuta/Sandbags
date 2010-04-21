import java.io.*;

public class test3 {
    public static void main(String[] args) {
	try {
	    for (int c = 0; c != -1;) {
		c = System.in.read();
		System.out.println(c);
	    }
	} catch(Exception e) {
	    e.printStackTrace();
	}
    }
}