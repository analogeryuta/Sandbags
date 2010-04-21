#!/usr/bin/perl

$str = "Now I know His strength is within me";
$str =~ /^(\w+)/;	# 先頭の単語にマッチ

print $1, "\n";	# マッチした値を表示
