#!/usr/local/bin/perl -w


#標準入力から引数を取る
print "Input > ";
$str = <STDIN>;
print "\n";

#改行文字を切り落とす
chomp($str);

#先頭が任意の1文字，後に "ing" がくる．
#後続に任意の文字が続き，列の末尾が "s" と一致する文字列の検索

if ($str =~ m|^.ing.*s$|) {
    print "$str は条件にあってるんじゃね? \n";
} else {
    print "なんか違うんじゃね? \n";
}
