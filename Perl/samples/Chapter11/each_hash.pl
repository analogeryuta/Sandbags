#!/usr/bin/perl

%hash = ('Akai', 'akai@domain.com', 'Ishikawa', 'ishi@domain.com');
while ( ($key, $value) = each(%hash) ) {
    print "key:$key, value:$value\n";
}


