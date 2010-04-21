import java.util.*;

public class CardPile {
	List<Card> contents;
	
	void open() {
		for Card c in contents {
			c.open();
		}
	}
}
