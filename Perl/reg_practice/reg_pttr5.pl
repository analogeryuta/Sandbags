#!/usr/local/bin/perl -w

#標準入力から文字列を受け取る
print "Input > ";
$word = <STDIN>;
print "\n";

chomp($word);

#文字列を複数にグループ化してパターンマッチ．
if ($word =~ m/(.{3})(.)(.*)/) {
    print "$1 \n";
    print "$2 \n";
    print "$3 \n";

    #試しにこんなprint文を実行してみよう．
    print STDOUT "$1 $2 $3 $word\n";
}
