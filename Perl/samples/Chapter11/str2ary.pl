#!/usr/bin/perl

$values = 'One,Two,Three';
@array = split( /,/, $values );
print $array[0], "\n";

print "@array", "\n";
