#!/usr/bin/perl

# 大文字すべての配列を得る
@alphabet = ('A' .. 'Z');
print @alphabet, "\n";

# 16 進の数字が得られますし、
$num = 10;
$hexdigit = (0 .. 9, 'a' .. 'f')[$num & 15];
print $hexdigit, "\n";

# 0 付きの日付が得られます
@z2 = ('01' .. '31');
$mday = 8;
print $z2[$mday], "\n";
