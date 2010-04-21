#!/usr/bin/perl -w

while(<>){	# 順に配列に入れる
    push(@buf,$_);
}
while(@buf){	# @bufは配列の長さを返す
    print pop(@buf);	# 後ろから取り出す
}
