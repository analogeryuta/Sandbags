#!/usr/bin/perl

@a = (9,8,7,6,5);
for ($i=0; $i<5; $i++) {
    print "@a \| ";
    print shift(@a) . "\n";
}

