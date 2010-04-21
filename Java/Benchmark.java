import java.io.*;
import java.util.*;

public class Benchmark {
    private long startTime;
    private long execTime;

    public Benchmark() {
	//constructor
    }

    public long getStartTime() {
	return startTime;
    }

    public long getExecTime() {
	return execTime;
    }

    public void start() {
	startTime = System.currentTimeMillis();
    }

    public void end() {
	execTime = System.currentTimeMillis() - startTime;
    }
}