/*
 * SineWaveProducer.java
 * 正弦波を表すbyte[]のデータを生成
 */

import java.util.*;
import java.io.*;

public class SineWaveProducer implements WaveProducer{
    private byte[] waveData;
    
    public SineWaveProducer() {
	//constructor
    }

    public byte[] getWaveData() {
	return waveData;
    }

    /*データ数sampling_freqだけ
     *audio_freqな周波数の波形データを出力
     */
    public void produceWave(int sampling_freq, int audio_freq) {
	//1周期毎にsamplingで取得されるsampleの数
	int sample_periodic = sampling_freq/audio_freq;
	double dr = 2d*Math.PI/(double)sample_periodic;
	waveData = new byte[sampling_freq];
	for (int i = 0; i < waveData.length; i++) {
	    waveData[i] = (byte)(Math.sin(dr*(double)i)*127d);
	}
    }

    public void printWaveData() {
	for (Object data: waveData) {
	    System.out.println(data);
	}
    }

//     public static void main(String[] args) {
// 	SineWaveProducer wp = new SineWaveProducer();
// 	wp.produceWave(22050, 440);
// 	wp.printWaveData();
//     }
}