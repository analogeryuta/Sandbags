import java.util.*;
import java.lang.*;
import javax.sound.sampled.*;

/*
 * AudioFormat(encoding, sampleRate, sampleSizeInBits, 
 *            channels, frameSize, frameRate, bigEndian)
 *  encoding - the audio encoding technique
 *  sampleRate - the number of samples per second
 *  sampleSizeInBits - the number of bits in each sample
 *  channels - the number of channels (1 for mono, 2 for stereo, and so on)
 *  frameSize - the number of bytes in each frame
 *  frameRate - the number of frames per second
 *  bigEndian - indicates whether the data for a single sample 
 *              is stored in big-endian byte order (false means little-endian)
 */

public class AudioListener implements Runnable {
    private volatile Thread blinker;
    private int interval=1000/30;

    public AudioListener() {
	//constructor
    }

    public void start() {
	blinker = new Thread(this);
	blinker.start();
    }

    public void stop() {
	blinker = null;
    }

    public void run() {
	Thread thisThread = Thread.currentThread();
	AudioFormat format;
	TargetDataLine line;

	//set audio format with the given parameters.
	format = new AudioFormat(AudioFormat.Encoding.PCM_SIGNED,
				 44100, 16, 2, 4, 44100, true);

	//check if this system is supported input audio or not
	DataLine.Info info = new DataLine.Info(TargetDataLine.class, format);
	if (!AudioSystem.isLineSupported(info)) {
	    System.out.println("Line matching " + info + " not supported.");
	    return;
	} else {
	    //print DataLine informations
	    System.out.println(info.toString());
	}

	//get and open the source data line for playback.
	try {
	    System.out.println("You can access the line");
	    line = AudioSystem.getTargetDataLine(format);
	    line.open(format, ((int)format.getSampleRate()/50)*5);
	} catch (Exception e) {
	    System.err.println("Unable to open the line: " + e);
	    return;
	}

	//main loop
	line.start();

	System.out.println("Enter main loop");
	while (blinker == thisThread) {
	        try {
		//take interval
		thisThread.sleep(1000);
	    } catch(InterruptedException e) {
		//error handler
	    }
	}
	System.out.println("Exit main loop");

	line.stop();
	line.flush();
	line.close();
    }
}