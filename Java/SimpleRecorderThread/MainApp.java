
public class MainApp {
    public static void main(String[] args) {
	if (args.length!=1) {
	    System.err.println("Usage: java MainApp filename");
	    return;
	} else { 
	    SimpleRecorder sr = new SimpleRecorder();
	    sr.setFileName(args[0]);
	    try {
		//start recording
		System.out.println("Start Recording: please press Enter key...");
		System.in.read();
		sr.initRecording();
		sr.startRecording();

		//stop recording
		System.out.println("Stop Recording: please press Enter key...");
		System.in.read();
		sr.stopRecording();

		System.exit(0);
	    } catch(Exception e) {
		e.printStackTrace();
		System.exit(1);
	    }
	}
    }
}