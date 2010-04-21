/*
 * CameraCaptureControler.java : OpenCV経由でcamera(iSight)を起動させる。
 * Threadを用い、applicationを生成。
 */
public class CameraCaptureControler extends Thread {
	final int FRAME_RATE=1000/30; //program execution frame rate (millisecond)
	CameraCaptureModel camera=null;
	CameraCaptureView gui=null;

	public CameraCaptureControler() {
	}
		
	public void start() {
		//OpenCV setup
		camera=new CameraCaptureModel();
		camera.setupCamera(320, 240);
		
		//GUI and Keyevent setup
		gui=new CameraCaptureView();
		gui.setupWindow(camera.width, camera.height);
		gui.setKeyEvent(camera.getCvInstance());
	}
	
	public void run() {
		System.out.println("run...");
		while(camera.getCvInstance()!=null) {
			try {
				Thread.sleep(FRAME_RATE);
				
				camera.grabCameraImage();
				
				camera.allocateImageBuffer();				
				gui.setCaputuredImage(camera.getVideoImage());
				
				gui.repaint();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}