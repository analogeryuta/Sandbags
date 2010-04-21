import java.lang.*;

public class MainApp {
    public static void main(String[] args) {
	if (args.length != 1) {
	    System.err.println("Usage: java MainApp freq");
	    return;
	}
	SimpleWave sw = new SimpleWave();
	sw.setAudioFreq(Integer.parseInt(args[0]));

	//initialize
	sw.initAudio();
	sw.makeWaveData();

	//start
	sw.startAudio();
	
	//write audio data
	sw.writeAudio();

	//stop
	sw.stopAudio();

	System.exit(0);
    }
}