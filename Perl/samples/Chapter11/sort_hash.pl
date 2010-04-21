#!/usr/bin/perl

%hash = ('Akai', 'akai@domain.com', 'Ishikawa', 'ishi@domain.com');

foreach $key ( sort keys %hash ) {
    print "key:$key, value:$hash{$key}", "\n";
}
