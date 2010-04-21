import java.io.*;
import java.awt.event.*;

public class SimpleKeyEvent implements KeyListener {
    public SimpleKeyEvent() {
	//constructor
    }

    public void keyPressed(KeyEvent e) {
	System.out.println("KeyPressed : " + e.getKeyChar());
    }
    
    public void keyReleased(KeyEvent e) {
	System.out.println("keyReleased : " + e.getKeyChar());
    }
    
    public void keyTyped(KeyEvent e) {
	System.out.println("keyTyped : " + e.getKeyChar());
    }
}