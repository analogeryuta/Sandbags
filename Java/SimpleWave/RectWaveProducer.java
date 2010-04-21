/*
 * RectWaveProducer.java
 * 矩形波を表すbyte[]のデータを生成
 */
import java.util.*;
import java.io.*;

public class RectWaveProducer implements WaveProducer {
    private byte[] waveData;
    
    public RectWaveProducer() {
	//constructor
    }

    public byte[] getWaveData() {
	return waveData;
    }

    public void produceWave(int sampling_freq, int audio_freq) {
	int periodic = sampling_freq/audio_freq;
	waveData = new byte[sampling_freq];

	for (int i = 0; i < waveData.length; i++) {
	    if ((i/periodic)%2 == 0) {
		waveData[i] = (byte)127;
	    } else {
		waveData[i] = (byte)-127;
	    }
	}
    }

    public void printWaveData() {
	for (Object data: waveData) {
	    System.out.println(data);
	}
    }

//     public static void main(String[] args) {
// 	RectWaveProducer wp = new RectWaveProducer();
// 	wp.produceWave(22050, 440);
// 	wp.printWaveData();
//     }
}