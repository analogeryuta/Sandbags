#!/usr/bin/perl

#  '-'を10個表示
print '-' x 10, "\n";

# $x を80回繰り返したものを$xに代入
$x = 'x';
$x x= 80;
print $x, "\n";

# 10個の(1, 1, ......, 1)と同様
@ones = (1) x 10;
print @ones, "\n"
