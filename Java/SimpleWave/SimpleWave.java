import java.util.*;
import java.io.*;
import javax.sound.sampled.*;

public class SimpleWave {
    private AudioFormat format;
    private DataLine.Info line_info;
    private SourceDataLine line;
    private byte[] waveData;
    private int sampling_freq = 22050;
    private int audio_freq = 440;

    public SimpleWave() {
	//constructor
    }

    public void initAudio() {
	//set audio format
	format = new AudioFormat(AudioFormat.Encoding.PCM_SIGNED,
                                 sampling_freq, 8, 2, 2, sampling_freq, false);

	//get DataLine.Info and check if access Line or not
	line_info = new DataLine.Info(SourceDataLine.class, format);
	if (!AudioSystem.isLineSupported(line_info)) {
	    System.out.println("Line matching " + line_info + " not supported");
	    return;
	} else {
	    System.out.println(line_info.toString());
	}

	//open data stream
	try {
	    line = AudioSystem.getSourceDataLine(format);
	    line.open(format);
	} catch (Exception e) {
	    System.out.println("Unable to open line: " + e);
	    return;
	}
	this.printInfo();
    }

    public void startAudio() {
	line.start();
    }

    public void stopAudio() {
	line.stop();
	line.flush();
	line.close();
    }

    //write wave data to line
    public void writeAudio() {
	line.write(waveData, 0, waveData.length);
	line.drain();
    }

    public void makeWaveData() {
	SineWaveProducer wave = new SineWaveProducer();
	wave.produceWave(sampling_freq, audio_freq);
	waveData = wave.getWaveData();
    }

    public void setAudioFreq(int f) {
	audio_freq = f;
    }

    void printInfo() {
        int buf_size = line.getBufferSize();
        int frame_size = format.getFrameSize();
        float frame_rate = format.getFrameRate();
        float sample_rate = format.getSampleRate();

        //check line's buffer size(in byte)
        System.out.println("audio buffer size (per sec): " + buf_size + " byte");

        //check frame size 
        System.out.println("frame size : " + frame_size + " byte");

        //check frame late in frames per second
        System.out.println("frame rate(per sec) : " + frame_rate + " fps");

        //check bufferd frame length in line data
        System.out.println("bufferd frame length (per sec): " + buf_size/frame_size);

        //check sample rate
        System.out.println("sample rate : " + sample_rate);
    }
}