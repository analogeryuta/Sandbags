import javax.xml.parsers.*;
import org.xml.sax.*;

public class ImpleName {

    public static void main( String[] argv ) {
        try {
            SAXParserFactory spf = SAXParserFactory.newInstance();
            System.out.println( spf.toString() );
            SAXParser parser = spf.newSAXParser();
            System.out.println( parser.toString() );
            XMLReader reader = parser.getXMLReader();
            System.out.println( reader.toString() );
        }
        catch( Exception e ) {
            System.err.println( e.toString() );
        }
    }
}
