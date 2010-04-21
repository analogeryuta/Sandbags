/*
 * CameraCaptureModel.java : OpenCV経由でcamera(iSight)を起動させる。
 * device, memory, opencvのsetupを実行。
 */
import java.awt.*;
import java.awt.image.*;
import hypermedia.video.OpenCV;
 
public class CameraCaptureModel extends Frame {
	/**
	 * fix for Eclipse's Warning.
	 */
	private static final long serialVersionUID = 1L;
	
	private OpenCV cv=null;         //OpenCV Object
	private Image frameImg=null;    //the input video stream image
	public int width;               //camera's width
	public int height;              //camera's height
	
	public CameraCaptureModel() {
	}
	
	/**
	 * return OpenCV instance.
	 */
	public OpenCV getCvInstance() {
		return cv;
	}

	/**
	 * return video frame image.
	 */
	public Image getVideoImage() {
		return frameImg;
	}
	
	/**
	 * setup OpenCV instance and camera. 
	 */
	public void setupCamera(int w, int h) {
		cv=new OpenCV();
		cv.capture(w, h);
		cv.cascade(OpenCV.CASCADE_FRONTALFACE_ALT);
		width=cv.width;
		height=cv.height;
	}
	
	/**
	 * grab image from video stream
	 */
	public void grabCameraImage() {
		cv.read();
	}
	
	/**
	 * create a new image from cv pixels data, then mapping to frame.
	 */
	public void allocateImageBuffer() {
		MemoryImageSource mis=new MemoryImageSource(cv.width, cv.height, cv.pixels(), 0, cv.width);
		frameImg=createImage(mis);
	}
}