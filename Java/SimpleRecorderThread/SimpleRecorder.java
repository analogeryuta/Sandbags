/*
 * SimpleRecorder.java : 指定したファイル名(.wav)にマイク入力を録音
 */
import java.util.*;
import java.io.*;
import java.lang.*;
import javax.sound.sampled.*;

public class SimpleRecorder implements Runnable {
    private volatile Thread blinker;
    private int interval = 1000/30;

    private AudioFormat format;
    private DataLine.Info info;
    private TargetDataLine line;
    private AudioInputStream audioInputStream;
    private File outFile;

    public SimpleRecorder() {
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

	System.out.println("Enter main loop.");
	while (blinker == thisThread) {
	    try {
		//do something below
		//write audio data to selected output file
		AudioSystem.write(audioInputStream, AudioFileFormat.Type.WAVE, outFile);
	    } catch (Exception e) {
		//error handler
		e.printStackTrace();
	    }
	}
	System.out.println("Exit main loop.");
    }

    public void initRecording() {
	//set audio format
	format = new AudioFormat(AudioFormat.Encoding.PCM_SIGNED,
				 44100, 16, 2, 4, 44100, false);

	//get DataLine.Info and check if access Line or not
	info = new DataLine.Info(TargetDataLine.class, format);
	if (!AudioSystem.isLineSupported(info)) {
	    System.out.println("Line matching " + info + " not supported");
	    return;
	} else {
	    System.out.println(info.toString());
	}

	//get and open data
	try {
	    line = AudioSystem.getTargetDataLine(format);
	    line.open(format);
	} catch (Exception e) {
	    System.err.println("Unable to open the line: " + e);
	    return;
	}

	//get audio input stream
	audioInputStream = new AudioInputStream(line);
    }

    public void startRecording() {
	line.start();
	this.start();
    }

    public void stopRecording() {
	line.stop();
	line.flush();
	line.close();
	this.stop();
    }

    public void setFileName(String s) {
	outFile = new File(s + ".wav");
    }
}