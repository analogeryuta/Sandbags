#!/usr/bin/perl

$str = "if you aint runnin game.\n";
($str2 = $str) =~ s/aint/are not/;
print $str, $str2;
