#!/usr/local/bin/perl

print "Content-type: text/html", "\n\n";

$command = "perl";
foreach my $key( split(/:/, $ENV{'PATH'}) ){
    $key =~ '.' if $key eq '';
    if ( -f "$key/$command" and -x _){
        print "$command was in $key\n";
    }
}
