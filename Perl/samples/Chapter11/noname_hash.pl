#!/usr/bin/perl -w

$ref_hash = {
    "element1" => "A",
    "element2" => "B",
};

# 要素を追加
$ref_hash->{"element3"} ="C";

#ハッシュ変数のリファレンスと同じ扱い方です．
print $$ref_hash{"element1"} . "\n";
