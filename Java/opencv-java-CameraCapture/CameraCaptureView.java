/*
 * CameraCaptureView.java : OpenCV経由でcamera(iSight)を起動させる。
 * applicationのGUIを設定。keyeventも追加。
 */
import java.awt.*;
import java.awt.event.*;
import hypermedia.video.OpenCV;

public class CameraCaptureView extends Frame {
	/**
	 * fix for Eclipse's Warning.
	 */
	private static final long serialVersionUID = 1L;
	
	private Image capturedImg=null;  //Captured frame image from Camera.
	
	public CameraCaptureView() {
		super("Camera Caputure Sample");		
	}

	/**
	 * set caputured frame image to CameraCaptureGUI instance.
	 */
	public void setCaputuredImage(Image img) {
		capturedImg=img;
	}

	/**
	 * Draw video frame.
	 */
	public void paint(Graphics g) {
		// draw image
		g.drawImage(capturedImg, 0, 0, null);
	}
	
	/**
	 * repaint frame image.
	 */
	public void repaint() {
	}
	
	/**
	 * getting opencv's instance, setup window and keyevent.
	 */
	public void setupWindow(int width, int height) {
		this.setBounds(100, 100, width, height);
		this.setBackground(Color.BLACK);
		this.setVisible(true);
	}
	
	/**
	 * set keyevent on GUI.
	 */
	public void setKeyEvent(final OpenCV cv) {
		this.addKeyListener(
				new KeyAdapter() {
					public void keyReleased(KeyEvent e) { 
						if (e.getKeyCode()==KeyEvent.VK_ESCAPE) { // ESC : release OpenCV resources 
							cv.dispose();
							System.exit(0);
						}
					}
				}
			);
	}
}