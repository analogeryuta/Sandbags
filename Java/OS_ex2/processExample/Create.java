package processExample;

import java.io.*;

/**
 * @author kono
 *
 */

public class Create {
	static final int BUFSIZE = 4096;
	
	static public void main(String [] args) throws IOException {
		Process p = new ProcessBuilder("/usr/bin/cal", "5","2006").start();
		InputStream out = p.getInputStream();
		byte[] buf = new byte[BUFSIZE];
		int length;
		while((length=out.read(buf))>0) {
			System.out.write(buf,0,length);
		}
	}
}
