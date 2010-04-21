import javax.xml.parsers.*;
import org.xml.sax.*;

/** SAX Parse Test */
public class ParseTest {

  /** Reader */
    private XMLReader reader = null;

  /** Constructor */
    public ParseTest() {
        try {
            SAXParserFactory spf = SAXParserFactory.newInstance();
            SAXParser parser = spf.newSAXParser();
            reader = parser.getXMLReader();
            reader.setContentHandler( new MyContentHandler() );
            reader.setErrorHandler( new MyErrorHandler() );
        }
        catch( Exception e ) {
            System.err.println( e.toString() );
        }
    }

  /** main (start here) */
    public static void main( String[] args ) {
        try {
            ParseTest test = new ParseTest();
            InputSource source = new InputSource( args[0] );
            test.reader.parse( source );
        }
        catch( Exception e ) {
            System.err.println( e.toString() );
        }
    }
}
