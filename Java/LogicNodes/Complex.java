
public class Complex {
	double real;
	double image;
	
	Complex(double _real1, double _image1) {
		real = _real1;
		image = _image1;
	}

	Complex add(Complex a, Complex b) {
		return new Complex(a.real + b.real, a.image + b.image);		
	}
	
}
