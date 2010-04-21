import java.util.*;
import java.io.*;

public class catString {
    public catString() {
	//constructor
    }

    public static void main(String[] args) {
	Benchmark b = new Benchmark();
	
	if (args.length!=2) {
	    System.err.println("Usage: java catString str1 str2");
	    return;
	}

	b.start();
	for (int i=0; i<2000; i++) System.out.println(args[0] + ".wav." + args[1]);
	b.end();
	System.out.println(b.getExecTime());
    }
}