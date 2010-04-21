
import java.awt.*;

public class Plotter extends Canvas {
	private int maxValue, minValue;
	private Canvas canvas;
	private byte[] data;


	public Plotter(int minValue, int maxValue) {
		this.minValue=minValue;
		this.maxValue=maxValue;
	}

	public void paint(Graphics g) {
		g.drawRoundRect(0,0, getWidth(), getHeight(), 5, 5);
		if (data==null || data.length==0)  return;

		int size = data.length;
		int height = getHeight();
		float xstep = (float)this.getWidth()/(float)size;
		float p = (float)height/((float)maxValue-(float)minValue);

		// first value
		float value=(float)height - (data[0]-minValue)*p;

		for (int i=1; i<size; i++) {
			float prevValue;
			prevValue = value;
			value = (float)height - (data[i]-minValue)*p;
			assert value<=height;
			assert value>0;

			g.drawLine( (int)((i-1)*xstep), (int)prevValue, (int)((i)*xstep), (int)value);
		}
	}
	/*
	 *  Heigh - (value-minV)/(maxV-minV)*Height
	 *  = (Height+/
	 */

	public void setData(byte[] data) {
		this.data = data;
	}
}




