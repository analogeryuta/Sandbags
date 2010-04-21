#!/usr/local/bin/perl -w

#"ls" の出力をパイプで受け取り，ログファイルに書き込むスクリプト．
#open()を無駄にやってる感じがする．もっと良い書き方があるはずだ

my $COMMAND = "ls";          #マクロを定義しようと思ったけどいいや．

#ログファイルをopen()する．
if (open(OUT,">> output_log")) {   #open()が成功したかどうか，条件判定してみる．
    open(IN, "$COMMAND |");        #コマンドのパイプ入力用にopen()を行う．
    while ($out_buf = <IN>) {
	print OUT $out_buf;
	print $out_buf;            #$out_bufの確認用
    }
    print OUT "\n"."区切りの確認\n";   #前回のログとの区切りをいれてみよう．
    close(IN);
} else {
    die "ログファイルをopenできません\n";
}
close(OUT);                      #ログファイルをcloseする．
