#!/usr/bin/perl

sub kansu{
    $_[0] = 100;
}

my $x = 1;
print $x, "\n";

&kansu( $x ); # この時点で $x の値は「100」に変更されます
print $x, "\n";
