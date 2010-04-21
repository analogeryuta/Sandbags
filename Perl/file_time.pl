#!/usr/local/bin/perl -w

#引数に指定したファイルの情報を取得する．
#stat('file_name')で，関数stat()で指定したファイル(file_name)
#の更新日時，最終アクセス日を取得する．


#statで返される情報は以下の13個．
my @info_str = qw(dev ino mode nlink uid gid rdev size atime mtime ctime blk_size blocks);

#stat()の返す情報を配列内に格納する.
@stat_str = stat($ARGV[0]);
$ary_length = @stat_str;

#出力する文字列を持つ
my @print_str;

for ($cnt=0; $cnt<$ary_length; $cnt++) {
    if (($cnt==8)||($cnt==9)||($cnt==10)) {
    $print_str[$cnt] = localtime($stat_str[$cnt]);
    } else {
	$print_str[$cnt] = $stat_str[$cnt];
    }
}

for ($cnt=0; $cnt<$ary_length; $cnt++) {
    print "$info_str[$cnt] : $print_str[$cnt] \n";
}
