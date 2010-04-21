#!/usr/bin/perl

# 要素に値を代入
$list[0][0] = "Jini";

# リファレンスを使って全体を表示
for my $ref( @ list ){
    print "@$ref\n";
}

# 1つずつ全体を表示（シンプルな方法）
for my $ref( @list ){
    for $ref2( @{$ref} ){
        print $ref2, "\n";
    }
}

# 1つずつ全体を表示
for my $i( 0 .. $#list ){
    for $j ( 0...$#{$list[$i]} ){
        print "$i $j : $list[$i][$j]\n";
    }
}
