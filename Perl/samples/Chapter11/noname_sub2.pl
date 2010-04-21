#!/usr/bin/perl

@subs = qw(Yahoo Google Excite);
foreach my $key( @subs ){
    ${ "print" . $key } = sub { print "$key\n" };
}

&$printYahoo();
