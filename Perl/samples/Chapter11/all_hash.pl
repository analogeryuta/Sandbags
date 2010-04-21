#!/usr/bin/perl

%hash = ('Akai', 'akai@domain.com', 'Ishikawa', 'ishi@domain.com');

foreach $key ( keys %hash ) {
    print "$key : $hash{$key}", "\n";
}
