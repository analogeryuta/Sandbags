import java.util.*;

public class test2 {
    public static void main(String[] args) {
	byte[] buf = new byte[4];
	try {
	    System.in.read(buf);
	    System.out.println(buf);
	} catch (Exception e) {
	    e.printStackTrace();
	}
    }
}