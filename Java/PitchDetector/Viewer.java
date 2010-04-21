import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowListener;
import java.awt.event.WindowEvent;
import javax.sound.sampled.*;

public class Viewer extends Frame {
	private Plotter plotter;
	private Plotter sprPlotter;
	private Container controler;
	private AudioListener audioListener;
	private Button startButton;
	private Button stopButton;

// 	public static void main(String[] args) throws Exception{
// 		Viewer mw = new Viewer();
// 		mw.setVisible(true);
// 	}

	public Viewer() {
		super("viewer window");
		setSize(400, 600);
		setLayout(new BorderLayout());

		/* startButton  */
		startButton = new Button("Start");
		startButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				SpectrumViewer.this.startAudioListener();
			}
		});

		/* stopButton  */
		stopButton = new Button("Stop");
		stopButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				SpectrumViewer.this.stopAudioListener();
			}
		});

		/* control panel  */
		controler = new Container();
		controler.setLayout(new BorderLayout());
		controler.add(startButton, BorderLayout.EAST);
		controler.add(stopButton, BorderLayout.WEST);

		plotter = new Plotter(-128, 127);
		sprPlotter = new Plotter(0, 127);
		Container tmp = new Container();
		tmp.setLayout(new GridLayout(2,1));
		tmp.add(plotter);
		tmp.add(sprPlotter);

		/* Frame set  */
		add(tmp, BorderLayout.CENTER);
		add(controler, BorderLayout.NORTH);
		addWindowListener(new WindowListener() {
			public void windowActivated(WindowEvent e){ }
			public void windowClosed(WindowEvent e){ }
			public void windowDeactivated(WindowEvent e){ }
			public void windowDeiconified(WindowEvent e){ }
			public void windowIconified(WindowEvent e){ }
			public void windowOpened(WindowEvent e){ }
			public void windowClosing(WindowEvent e){
				System.out.println("exit");
				System.exit(0);
			}
		});
	}

	public void startAudioListener() {
		AudioFormat format;
		//format = new AudioFormat(8000, 8, 1, true, true);
		format = new AudioFormat(AudioFormat.Encoding.PCM_SIGNED, 
				16000, 8, 1, 1, 16000, true);
		audioListener = new AudioListener(format, plotter, sprPlotter, 50,true);
		audioListener.start();
		System.out.println("start button was clicked");
		System.out.println("frame rate: "+format.getFrameRate());
		System.out.println("frame size: "+format.getFrameSize());
		//System.out.println("property: "+format.getProperty());
		System.out.println("sample rate: "+format.getSampleRate());
		System.out.println("sample bits: "+format.getSampleSizeInBits());
		System.out.println("big endian: "+format.isBigEndian());
	}

	public void stopAudioListener() {
		audioListener.stop();
		audioListener=null;
		System.out.println("stop button was clicked");
	}
}
