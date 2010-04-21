package fileExample;

import java.io.IOException;

public class StdoutCopy {
	static final int BUFSIZE = 4096;

	/**
	 * @param args
	 * @throws IOException 
	 * @throws IOException
	 * 
	 * File copy
	 */
	public static void main(String args[]) throws IOException  {
		int len;	
		byte[] buf = new byte[BUFSIZE];
	
		while((len=System.in.read(buf,0,BUFSIZE))>0) {
			System.out.write(buf,0,len);
		}
		System.out.close();
	}

}
