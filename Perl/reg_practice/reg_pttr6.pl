#!/usr/local/bin/perl -w

print "Input > ";
$word = <STDIN>;
print "\n";

chomp($word);

#ブラケット("[ ]"です) を使ったパターンマッチの実行．
if ($word =~ m/[a-z]{3}[A-Z].*[0-9]$/) {
    print "Cの関数名定義例その1，みたいな? \n";
} elsif ($word =~ m/^[A-Z][a-z]+_[^0-9]+[0-9]$/) {
    print "Cの関数名定義例その2，みたいな? \n";
} else {
    print "なんか,俺の好みと合わないよ．\n";
}
