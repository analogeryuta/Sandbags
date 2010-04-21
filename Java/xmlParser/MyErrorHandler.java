import org.xml.sax.*;

/** Error Handler */
public class MyErrorHandler implements ErrorHandler  {

  /** error */
    public void error( SAXParseException e ) throws SAXException {

        System.err.println( "Error line:"
                 + e.getLineNumber() + ":" + e.getMessage() );
        System.exit(-1);
    }

  /** fatal error */
    public void fatalError( SAXParseException e ) throws SAXException {

        System.err.println( "Fatal Error line:"
                 + e.getLineNumber() + ":" + e.getMessage() );
        System.exit(-1);
    }

  /** warning */
    public void warning( SAXParseException e ) throws SAXException {

        System.err.println( "Warning line:"
                 + e.getLineNumber() + ":" + e.getMessage() );
    }
}
