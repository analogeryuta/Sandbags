#!/usr/bin/perl

# リストリファレンスのリストへのリファレンスをスカラ変数に代入
$ref_array = [ 
    [1, 2], 
    [3, 4], 
];

print $ref_array->[1][1];
