/*
 * SimpleMixer.java
 * 指定したファイル名(.wav)にマイク入力を録音
 * 録音時間を引数として入力させる予定
 * AudioSystem.getLine()ではなく、Mixer経由でLineを取る
 */
import java.util.*;
import java.io.*;
import java.lang.*;
import javax.sound.sampled.*;

public class SimpleMixer {
    private AudioFormat format;
    private Mixer.Info[] mixer_info;
    private DataLine.Info[] line_info;
    private Mixer mixer;
    private TargetDataLine line;
    private File outFile;
    private boolean recordable = false;

    public SimpleMixer() {
	//constructor
    }
    
    public void initRecording() {
	//using Mixer.Info[] info !!
	//get Mixer.Info instance and get system default mixer object.
	//mixer_info = AudioSystem.getMixerInfo();
	mixer = AudioSystem.getMixer(null);

	//set audio format
	format = new AudioFormat(AudioFormat.Encoding.PCM_SIGNED,
				 44100, 16, 2, 4, 44100, false);

	//get Line.Info and check if access Line or not
	line_info = mixer.getTargetLineInfo();
	if (!mixer.isLineSupported(line_info)) {
	    System.out.println("Line matching " + line_info + " not supported");
	    return;
	} else {
	    System.out.println(line_info.toString());
	}

	//get data and open data stream
	try {
	    //line = AudioSystem.getTargetDataLine(format);
	    line = (TargetDataLine)mixer.getLine(line_info);
	    line.open(format);
	    this.printInfo();
	} catch (Exception e) {
	    System.err.println("Unable to open the line: " + e);
	    return;
	}	
    }

    public void startRecording() {
	line.start();
    }

    public void stopRecording() {
	line.stop();
	line.flush();
	line.close();
    }

    public void writeRecording() {
	int numBytesRead = 0;
	long startTime;
	long timeLeft = 0;
	ByteArrayInputStream in;
	ByteArrayOutputStream out = new ByteArrayOutputStream();
	byte[] readData = new byte[line.getBufferSize()/5];
	
	//ループ処理が10秒以上経ったら終了(かなり怪しいけど)
	//44100*4*10
	startTime = System.currentTimeMillis();
	while (true) {
	    numBytesRead = line.read(readData, 0, readData.length);
	    out.write(readData, 0, numBytesRead);

	    timeLeft = System.currentTimeMillis() - startTime;
	    if (timeLeft >= 10000) break;
	}

	//whileを抜けた後のtimeLeftとnumBytesReadの確認
	System.out.println("time left : " + timeLeft);
	System.out.println("numBytesRead : " + numBytesRead);

	//OutputStreamからInputStreamへ変換
	in = new ByteArrayInputStream(out.toByteArray());
	System.out.println("Array length : " + in.available());

  	try {
  	    //write audio data to selected output file
	    AudioInputStream audio_io = new AudioInputStream(in, format, in.available());
  	    AudioSystem.write(audio_io, AudioFileFormat.Type.WAVE, outFile);
  	} catch (Exception e) {
  	    //error handler
  	    e.printStackTrace();
  	    return;
  	}
    }

    public void setFileName(String s) {
	outFile = new File(s + ".wav");
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