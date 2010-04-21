/*
 * FaceDetection.java : sample for opencv on java
 * 
 */

import java.awt.*;
import java.awt.event.*;
import java.awt.image.MemoryImageSource;
import hypermedia.video.OpenCV;
 
public class FaceDetection extends Frame implements Runnable {
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
	
	// list of all face detected area
	Rectangle[] squares=new Rectangle[0];
	
	//counter
	int counter=0;
	/**
	 * Setup Frame and Object(s).
	 */
	public FaceDetection() {
		//このなかでいろいろ書くのはさけて
		//guiは分離,
		super("Face Detection Sample");
			
		// OpenCV setup
		cv=new OpenCV();
		cv.capture(320, 240);
		cv.cascade(OpenCV.CASCADE_FRONTALFACE_ALT);
		
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
		
		// start running program
		t=new Thread(this);
		t.start();
	}
		
	/**
	 * Draw video frame and each detected faces area.
	 */
	public void paint(Graphics g) {		
		// draw image
		g.drawImage(frame, 0, 0, null);
		
		// draw squares
		g.setColor(Color.RED);
		for(Rectangle rect : squares)
			g.drawRect(rect.x, rect.y, rect.width, rect.height);
	}
	
	/**
	 * Execute this sample.
	 */
	
	//print detected face's axis(x, y) into captured buffer
	//System.out.println("x: "+ (squares[0].x + (squares[0].x/2)) +"　y: " + (squares[0].y + (squares[0].y/2)) );
	//上のメソッドをwait()してcallする。stdoutに検出した顔の位置座標をprintしたいので。
	public void run() {
		System.out.println("run...");
		while(t!=null && cv!=null) {
			try {
					Thread.sleep(FRAME_RATE);
				
					// grab image from video stream
					cv.read();
				
					// create a new image from cv pixels data
					MemoryImageSource mis=new MemoryImageSource(cv.width, cv.height, cv.pixels(), 0, cv.width);
					frame = createImage(mis);
				
					// detect faces
					squares=cv.detect(1.2f, 2, OpenCV.HAAR_DO_ROUGH_SEARCH, 20, 20);
					counter=0;
					for(Rectangle rect : squares) {
						//print detected face's axis(x, y) on captured buffer
						counter++;
						System.out.println("obj"+counter+" x: "+ (rect.x + (rect.x/2)) +"　y: " + (rect.y + (rect.y/2)) );
					}
					// of course, repaint
					repaint();
			} catch(InterruptedException e) {;}
		}
	}
}