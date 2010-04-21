#!/usr/bin/perl

$str = "back Looking";
$str =~ s/([^ ]*) *([^ ]*)/$2 $1/;	# 最初の2語の入れ替え
print $str, "\n";
