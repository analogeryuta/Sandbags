#!/usr/local/bin/perl -w

my @arg_ary = @ARGV;
$argc = @arg_ary;

foreach $argv (@arg_ary) {
    print "$argv \n";
}

print "$argc \n";
