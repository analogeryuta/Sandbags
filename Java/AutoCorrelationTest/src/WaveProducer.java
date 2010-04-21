public interface WaveProducer {
    byte[] getWaveData();
    void produceWave(int sampling_freq, int audio_freq);
    void printWaveData();
}