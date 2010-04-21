#!/usr/local/bin/perl

# 1.環境変数REQUEST_METHODをチェックしてリクエストメソッド（GETまたはPOST）を判断する。
if( $ENV{'REQUEST_METHOD'} eq "GET" ) {
# 2.GETであれば、環境変数QUERY_STRINGからクエリを読み込む。
    $buffer = $ENV{'QUERY_STRING'};
} else {
# 3.POSTであれば、環境変数CONTENT_LENGTHを使用してリクエストのサイズを調べ、標準入力からクエリを読み込む。
    read( STDIN, $buffer, $ENV{'CONTENT_LENGTH'} );
}

print "Content-Type: text/html", "\n\n";

print "<b>Data</b> ", $buffer, "<br>\n";
print "<b>Split Data</b><br> ", "\n";

# 4.クエリをクエスチョン（ ? ）で分割する。
my @pairs = split(/&/,$buffer);
foreach $pair (@pairs){
# 5.キーと値に分割する（key=value&key=value...）。
    my($name, $value) = split(/=/, $pair);
# 6.スペース（ ）をプラス（+）に変換する。
    $value =~ tr/+/ /;
# 7.16進数にエンコードされた文字列をデコードする。
    $value =~ s/%([a-fA-F0-9][a-fA-F0-9])/pack("C", hex($1))/eg;
    print "$name : $value<br>";
}
