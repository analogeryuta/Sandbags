import java.lang.*;

public class MainApp {
    public static void main(String[] args) {
	//正弦波データの生成
	WaveProducer wp = new SineWaveProducer();
	wp.produceWave(22050, 440);
	//wp.printWaveData();

	//自己相関を実行
	AutoCorrelation ac = new AutoCorrelation();
	byte[] ac_data = ac.process(22050, wp.getWaveData());

	int i=0;
	for (Object data: ac_data) {
	    System.out.println(i++ + " " + data);
	}
    }
}