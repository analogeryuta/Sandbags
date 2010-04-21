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

public class CheckMixer {
    private AudioFormat format;
    private Line.Info[] line_info;
    private Mixer mixer;
    private TargetDataLine line;

    public CheckMixer() {
	//constructor
    }
    
    public void checkLineInfo() {
	//using Mixer.Info[] info !!
	//get Mixer.Info instance and get system default mixer object.
	mixer = AudioSystem.getMixer(null);

	//set audio format
	format = new AudioFormat(AudioFormat.Encoding.PCM_SIGNED,
				 44100, 16, 2, 4, 44100, false);

	//get Line.Info and check if access Line or not
	line_info = mixer.getTargetLineInfo();
	System.out.println(line_info.length);
    }


}