#!/usr/bin/perl

$w = 'BOOK@RFS.CO.JP';
$w =~ tr/A-Z/a-z/; # 小文字に正規化
print $w,"\n";


$cnt = $w =~ tr/././;	# $w に含まれる . の数を数える
print $cnt,"\n";


$w =~ tr/a-zA-Z/ /cs;	# 英字以外をスペースに変換
print $w,"\n";


$w =~ tr/a-zA-Z//s;	# 連続した単語をひとつにまとめる
print $w,"\n";
