/*
 *AutoCorrelation.java:
 *byte[]に格納された音声データに対して自己相関を行う。
 *データの各サンプルの精度は今のところ、8bitで決めうち中。
 *要変更。
 */
import java.io.*;
import java.util.*;

public class AutoCorrelation {
    public AutoCorrelation() {
	//constructor
    }

    public byte[] process(int n, byte[] data) {
	byte sum[] = new byte[n];
	byte tau = 0;
	int hi = n;

	for (int i = 0; i < hi; i++) {
	    sum[i] = 0;
	    for (int j = 0; j < hi; j++) {
		sum[i] += data[j] * data[i+j];
	    }
	    sum[i] /= hi;
	    if (i == 0)
		tau = sum[i];
	    sum[i] /= tau;
	}

	return sum;
    }
}