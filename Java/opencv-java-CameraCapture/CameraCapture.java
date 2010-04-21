/*
 * CameraCapture.java : sample for opencv on java
 * 
 */

import java.awt.*;
import java.awt.event.*;
import java.awt.image.MemoryImageSource;
import hypermedia.video.OpenCV;
 
public class CameraCapture extends Frame implements Runnable {
	/**
	 * fix for Eclipse's warning
	 */
	private static final long serialVersionUID = 1L;

	// program execution frame rate (millisecond)
	final int FRAME_RATE=1000/30;
	
	OpenCV cv=null;	// OpenCV Object
	Thread t=null;	// the sample thread
	
	// the input video stream image
	Image frame=null;
	MemoryImageSource mis=null;
	
	/**
	 * Setup Frame and Object(s).
	 */
	public CameraCapture() {
		super("Camera device capture Sample");
		this.setupCamera();
		this.setupWindow();
		//this.allocateImageBuffer();
		this.startThread();
	}

	/**
	 * starting thread
	 */
	public void startThread() {
		// start running program
		t=new Thread(this);
		t.start();
	}
	
	/**
	 * setup camera
	 */
	public void setupCamera() {
		// OpenCV setup
		cv=new OpenCV();
		cv.capture(320, 240);
		cv.cascade(OpenCV.CASCADE_FRONTALFACE_ALT);
	}
	
	/**
	 * setup window and keyevent
	 */
	public void setupWindow() {
		// frame setup
		this.setBounds(100, 100, cv.width, cv.height);
		this.setBackground(Color.BLACK);
		this.setVisible(true);
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
	
	/**
	 * setup memory image
	 */
	public void allocateImageBuffer() {
		mis=new MemoryImageSource(cv.width, cv.height, cv.pixels(), 0, cv.width);
	}
	
	/**
	 * Draw video frame and each detected faces area.
	 */
	public void paint(Graphics g) {		
		// draw image
		g.drawImage(frame, 0, 0, null);
	}
	
	/**
	 * Execute this sample.
	 */
	public void run() {
		System.out.println("run...");
		while(t!=null && cv!=null) {
			try {
					Thread.sleep(FRAME_RATE);
				
					// grab image from video stream
					cv.read();

					// create a new image from cv pixels data
					allocateImageBuffer();
					frame=createImage(mis);
					
					// of course, repaint
					repaint();
			} catch(InterruptedException e) {;}
		}
	}
}