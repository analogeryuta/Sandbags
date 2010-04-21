#!/usr/bin/perl

package pkg1;	# パッケージ名pkg1の宣言

$value = "It's getting exciting now !";

#-------------------------------------------------#

package pkg2;	# パッケージ名pkg2の宣言

print $value, "\n";	# pkg2では$valueが宣言されていないのでエラー

print $pkg1::value;	# 成功です。pkg1の変数を呼び出しています
