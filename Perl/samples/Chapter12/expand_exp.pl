#!/usr/bin/perl

$w = "PATTERN";

# 2つの文は同じことをしています。
print "OK\n" if $w =~ /pattern/i;
print "OK\n" if $w =~ /(?i)pattern/;
