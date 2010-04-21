import java.lang.*;

public class MainApp {
    public static void main(String[] args) {
	if (args.length != 1) {
	    System.err.println("Usage: java MainApp filename");
	    return;
	}
	SimpleRecorder sr = new SimpleRecorder();
	sr.setFileName(args[0]);

	//start recording
	sr.initRecording();
	sr.startRecording();

	//recording loop
	sr.writeRecording();

	//stop recording
	sr.stopRecording();
	System.exit(0);
    }
}