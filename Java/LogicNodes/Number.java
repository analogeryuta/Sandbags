
public class Number {
Object n;

	Number(int i) {
		n = (Object)new Integer(i);
	}
	Number(float f) {
		n = (Object)new Float(f);
	}
	Number(double d) {
		n = (Object)new Double(d);
	}
}


