/**
 * Theremin0.java
 * JAVAテルミンテスト版
 *
 * $Id: Theremin0.java 880 2004-11-24 06:43:26Z propella $
 *
 * @author YAMAMIYA Takasi
 * @version 1.0
 */

import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;


public class Theremin0 extends Applet {

	RectWave tone = new RectWave(440);
	int FREQUENCY_MAX = 2000;
	Dimension size = new Dimension();
	String status;

	public void init() {
		size = this.getSize();

		this.addMouseListener(
							  new MouseAdapter() {
									  public void mouseEntered(MouseEvent e) {
										  if (tone.isRunning) return;
										  tone = new RectWave(440);
										  tone.start();
									  }
									  public void mouseExited(MouseEvent e) {
										  tone.off();
									  }
								  }
							  );

		this.addMouseMotionListener(
									new MouseMotionAdapter() {
											public void mouseMoved(MouseEvent e) {
												int x = e.getX();
												int y = e.getY();
												if (size.width <= 0) return;
												float frequency = FREQUENCY_MAX * x / size.width;
												float volume = 1 - 1f * y / size.width;
												tone.setFrequency(frequency);
												tone.setVolume(volume);
												status = "freq:"+frequency+" volume:"+volume;
												repaint();
											}
										}
									);

	}

	public void destroy() {
		tone.off();
	}

    public void paint( Graphics g ) {
		showStatus(status); 
	}
}
