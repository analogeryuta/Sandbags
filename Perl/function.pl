#!/usr/bin/perl -w


#サブルーチン定義時に引数まで記述する必要はないのか．．．
sub func1() {
    for ($i=0; $i<$_[1]; $i++) {
	print "hello!! $_[0] \n";
    }
}

#こんな感じで．．
sub func2() {
    $tmp = shift;
    $tmp =~ s/$tmp/hogehoge/;
    print $tmp."\n";
}

&func1("world", 6);
&func2("fink");
