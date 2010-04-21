import java.awt.*;
import java.awt.image.*;
import java.awt.event.*;

public class Game extends Frame {
	private Image cardImage;
	
	public Game() {
		super("");
		//表示イメージファイル名を""内に入れる
		cardImage = getToolkit().createImage("");
	}
	public void paint(Graphics g) {
	g.drawImage(cardImage, 0, 0, this);	
	}
	public static void main(String args[])
	{
	new Game();	
	}
	
}
