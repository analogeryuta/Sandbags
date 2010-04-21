#!/usr/local/bin/perl -w

#標準入力から文字列を受け取ろう．
print "Input > ";
$input = <STDIN>;

#改行文字の切り落とし
chomp($input);

#特定の文字列を別の文字列へ置換する
$input =~ s/finger/MacOSX /;
print $input."\n";
