#!/usr/local/bin/perl -w

print "input your name : ";
$str = <STDIN>;

open(OUT,">> input_log");
print OUT $str;
close(OUT);

#for ($cnt=0; $cnt<@file; $cnt++) {
 #   print  $file[$cnt] . "\n";
#}

print "hello! $str";
