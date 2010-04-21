package fileExample;

import java.io.*;


/**
 * @author kono
 *
 *   Simple File Operation using Java language
 *   2006/10/1
 */

public class Dir {
	/**
	 * @param args
	 * @throws IOException
	 * 
	 * File listing
	 */
	public static void main(String args[]) throws IOException {
		
		File file;
		
		System.out.println(args[0]);
		file = new File(args[0]);
		if (! file.exists()) {
			System.out.println(" does not exist.");
			return;
		}
		if (file.isDirectory()) {
			String[] list;
			list = file.list();
			//
			//  fill it by yourself:
			//
		}
		Stat.printStat(file,System.out);
		
	}
	

}

