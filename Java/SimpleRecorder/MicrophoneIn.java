/**
 *
 * MicrophoneIn.java
 * 10秒間マイクから録音し、その後ファイルへ書き出します
 * @author fukugawa
 *
 */

import java.io.*;
import javax.sound.sampled.*;

public class MicrophoneIn {
    public static void main(String[] args) {
	// リニアPCM 16bit 8000Hz × 10秒間 = 160000byte
	byte[] voiceData = new byte[160000];
                
	try {
	    System.out.println("マイク入力開始...");
                        
	    // リニアPCM 8000Hz 16bit モノラル 符号付き リトルエンディアン
	    AudioFormat linearFormat = new AudioFormat(8000,16,1,true,false);
                        
	    // ターゲットデータラインを取得する
	    DataLine.Info info = new DataLine.Info(TargetDataLine.class,linearFormat);
	    TargetDataLine targetDataLine = (TargetDataLine)AudioSystem.getLine(info);
                        
	    // ターゲットデータラインをオープンする
	    targetDataLine.open(linearFormat);
                        
	    // マイク入力開始
	    targetDataLine.start();
                        
	    // ターゲットデータラインから入力ストリームを取得する
	    AudioInputStream linearStream = new AudioInputStream(targetDataLine);
                        
	    // 入力ストリームから音声データをByte配列へ取得する
	    linearStream.read(voiceData,0,voiceData.length);
                        
	    // マイク入力停止
	    targetDataLine.stop();
                        
	    // ターゲットデータラインをクローズする
	    targetDataLine.close();
                        
	    System.out.println("マイク入力停止");
                        
	    // AUファイルへ書き出す
	    File audioFile = new File("linear_pcm.au");
	    ByteArrayInputStream baiStream = new ByteArrayInputStream(voiceData);
	    AudioInputStream aiStream = new AudioInputStream(baiStream,linearFormat,voiceData.length);
	    AudioSystem.write(aiStream,AudioFileFormat.Type.AU,audioFile);
	    aiStream.close();
	    baiStream.close();
                        
	    System.out.println("ファイルへ書き出し終了");
	    System.exit(0);
	} catch(Exception e) {
	    e.printStackTrace();
	}
    }
}
