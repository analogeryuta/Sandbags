#!/usr/bin/perl

for ($i=5; $i<10; $i++) {
    unshift(@a, $i);	# @aの最初に$iを追加
}
print "@a";
