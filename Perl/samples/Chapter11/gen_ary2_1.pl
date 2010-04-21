#!/usr/bin/perl

# リストリファレンスのリストを配列に代入
@array = ( 
    [1, 2], 
    [3, 4],
);
print $array[0][0], "\n";

# foreachを使ってすべての要素にアクセス
foreach $key1 ( @array ){
    foreach $key2 ( @{ $key1 } ){
        print $key2;
    }
}
print "\n";

# forを使ってすべての要素にアクセス
for $i ( 0 .. $#array ){
    $ref = $array[$i];
    for $j ( 0 .. $#{ $ref } ){
        print $ref->[$j];
    }
}
print "\n";
