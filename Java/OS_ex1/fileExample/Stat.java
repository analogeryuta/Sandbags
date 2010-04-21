package fileExample;

import java.io.*;


/**
 * @author kono
 *
 *   Simple File Operation using Java language
 *   2006/10/1
 */

public class Stat {
	/**
	 * @param args
	 * @throws IOException
	 * 
	 * File stat
	 */
	public static void main(String args[]) throws IOException {
		
		File file;
		
		System.out.println(args[0]);
		file = new File(args[0]);
		if (! file.exists()) {
			System.out.println(" does not exist.");
			return;
		}
		printStat(file,System.out);
		
	}
	
	public static void printStat(File file,PrintStream out) {
	
	
		out.println(file.getAbsolutePath());
		if (file.isDirectory()) {
			out.println(" isDirectory");
		}
		if (file.canRead()) {
			out.println(" can read");
		} else {
			out.println(" cannot read");
		}	
		if (file.canWrite()) {
			out.println(" can write");
		} else {
			out.println(" cannot write");
		}
		out.print("length = "); out.print(file.length()); out.println();
		out.print("last modified = "); out.print(file.lastModified()); out.println();
		
	
	}
	

}
