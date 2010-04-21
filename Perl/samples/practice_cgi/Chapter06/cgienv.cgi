#!/usr/local/bin/perl

print "Content-type: text/html", "\n\n";

print "<HTML><BODY>", "\n";
print "<H1>´Ä¶­ÊÑ¿ô</H1><HR>", "\n";

foreach my $key( keys %ENV ){
    print "$key: $ENV{$key}<BR>", "\n";
}

print "<HR>", "\n";
print "</BODY></HTML>", "\n"; 
