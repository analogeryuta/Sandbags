#!/usr/local/bin/perl -w

#ファイルを読み込む．
open(IN,"< input_log");

#input_logを1行づつ読み込み,出力する
while ($buf = <IN>) {
    print $buf;
}

close(IN);
