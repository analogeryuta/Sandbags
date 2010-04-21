#!/usr/bin/perl

# スカラのリファレンスを作成
$word = "A";
$ref_word = \$word;

print $$ref_word, "\n";


# 配列のリファレンスを作成
@array = (1,2,3,4,5);
$ref_array = \@array;

print @$ref_array, "\n";


# ハッシュのリファレンスを作成
%hash = (element1=>"A", element2=>"B");
$ref_hash = \%hash;
while( ($key,$value) = each %$ref_hash ){
    print $key, " : ", $value, "\n";
}
