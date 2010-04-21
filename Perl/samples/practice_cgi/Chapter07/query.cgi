#!/usr/local/bin/perl

# GETメソッドの場合
if( $ENV{'REQUEST_METHOD'} eq "GET" ) {
    $buffer = $ENV{'QUERY_STRING'};
# POSTメソッドの場合
} else {
    read( STDIN, $buffer, $ENV{'CONTENT_LENGTH'} );
}

print "Content-Type: text/html\n\n\n";

print "<b>Method</b> ", $ENV{'REQUEST_METHOD'}, "<br>\n";
print "<b>Data</b> ", $buffer, "\n";
