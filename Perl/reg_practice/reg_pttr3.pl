#!/usr/local/bin/perl -w

#コマンドラインから文字列を受けとろう．
print "なんか文字入力して > ";
$input = <STDIN>;

#終端の改行文字を切り落とす
chomp($input);

#パターンマッチ:m修飾子の使用例
#複数行のうち，先頭が "f" か または末尾が "s"で終わる文字列の検索
if ($input =~ /^f|s$/m) {
    print "マッチしてんじゃね?\n";
} else {
    print "違うんじゃね? \n";
}
