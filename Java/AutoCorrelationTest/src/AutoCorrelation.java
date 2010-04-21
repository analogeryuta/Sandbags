/*
 *AutoCorrelation.java:
 *byte[]に格納された音声データに対して自己相関を行う。
 *データの各サンプルの精度は今のところ、8bitで決めうち中。
 *要変更。
 *
 */
import java.io.*;
import java.util.*;

public class AutoCorrelation {
    public AutoCorrelation() {
	//constructor
    }

    public byte[] process(int n, byte[] data) {
	byte sum[] = new byte[n];
	int tmp;

	for (int i = 0; i < n; i++) {
	    sum[i] = 0;
	    tmp = 0;
	    for (int j = 0; j < n - i; j++) {
		tmp += (int)data[j] * (int)data[i+j];
	    }
	    tmp /= n;
	    sum[i] = (byte)tmp;
	    sum[i] /= sum[0];
	}

	return sum;
    }
}