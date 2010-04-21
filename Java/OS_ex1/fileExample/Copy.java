package fileExample;
import java.io.*;

/**
 * @author kono
 *
 *   Simple File Operation using Java language
 *   2006/10/1
 */

public class Copy {
	static final int BUFSIZE = 4096;

	/**
	 * @param args
	 * @throws IOException
	 * 
	 * File copy
	 */
	public static void main(String args[]) throws IOException {
		
		File from;
		File to;
		FileReader reader;
		FileWriter writer;
		int len;
		char[] buf = new char[BUFSIZE];
		
		to = new File(args[1]);
		from = new File(args[0]);
		to.createNewFile();
		
		reader = new FileReader(from);
		writer = new FileWriter(to);
		
		while((len=reader.read(buf,0,BUFSIZE))>0) {
			writer.write(buf,0,len);
		}
		writer.close();
	}

}
