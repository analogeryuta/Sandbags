#!/usr/local/bin/perl

# GET�᥽�åɤξ��
if( $ENV{'REQUEST_METHOD'} eq "GET" ) {
    $buffer = $ENV{'QUERY_STRING'};
# POST�᥽�åɤξ��
} else {
    read( STDIN, $buffer, $ENV{'CONTENT_LENGTH'} );
}

print "Content-Type: text/html\n\n\n";

print "<b>Method</b> ", $ENV{'REQUEST_METHOD'}, "<br>\n";
print "<b>Data</b> ", $buffer, "\n";
