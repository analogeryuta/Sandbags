#!/usr/local/bin/perl -w

$word = "ABCDEF";


#文字列 $word を１文字づつパターンマッチさせ，
#配列に格納していくだけ．

while ($word =~ /(..)(.)/g) {
    push(@word, $1);
    push(@word, $2);
}

print "@word \n";

$word2 = "windows";

if ($word2 =~ /WINDOWS/i) {
    print "条件に合ってるんじゃね? \n";
} else {
    print "なんかちがうんじゃね? \n";
}

