#!/usr/bin/perl

my $global = "It's getting exciting now !";
{
    my $local = "Think of everything we've accomplished.";
}

print $global, "\n";

print $local, "\n";	# $localは有効範囲外で利用できません！
