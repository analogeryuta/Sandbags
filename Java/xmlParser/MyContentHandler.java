import org.xml.sax.*;

/** content handler */
public class MyContentHandler implements ContentHandler  {

  /** start parsing */
    public void startDocument() throws SAXException {

        System.out.println( "Now, Start parsing..." );
        System.out.println( "-------------------------------" );
    }

  /** end parsing */
    public void endDocument() throws SAXException {

        System.out.println( "" );
        System.out.println( "-------------------------------" );
        System.out.println( "...Ok, Finished parsing." );
    }

  /** element */
    public void startElement( String nameSpace, String localName,
                              String qName, Attributes attrs )
                              throws SAXException {

        System.out.print( "(Tag:" + qName + " begins.)" );
    }

  /** end element */
    public void endElement( String nameSpace, String localName,
                            String qName )
                            throws SAXException {

        System.out.print( "(Tag:" + qName + " ends.)" );
    }

  /** text */
    public void characters( char[] ch, int start, int length )
                            throws SAXException {
        String text = new String( ch, start, length );
        System.out.print( text );
    }

  /** set Locator */
    public void setDocumentLocator ( Locator locator ) {

        System.out.println( locator.getSystemId() + ":"
                          + locator.getPublicId() + ":"
                          + locator.getLineNumber() + ":"
                          + locator.getColumnNumber() );
    }
    
  /** Start Name Space Mapping */
    public void startPrefixMapping ( String prefix, String uri )
                                     throws SAXException {
        System.out.println( "startPrefixMapping() is called." );
    }

  /** End Name Space Mapping */
    public void endPrefixMapping ( String prefix )
                                   throws SAXException {
        System.out.println( "endPrefixMapping() is called." );
    }
    
  /** white space */
    public void ignorableWhitespace ( char ch[], int start, int length )
                                      throws SAXException {
        System.out.println( "ignorableWhitespace() is called." );
    }
    
  /** processing instruction */
    public void processingInstruction ( String target, String data )
                                        throws SAXException {
        System.out.println( "processingInstruction() is called." );
    }

  /** skip entity */
    public void skippedEntity ( String name )
                                throws SAXException {
        System.out.println( "skippedEntry() is called." );
    }
}
