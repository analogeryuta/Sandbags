# 次の2行は数値をパックしてバイトの並びにします。
print pack("cccc",65,66,67,68), "\n";

print pack("c4",65,66,67,68), "\n";


# "a"フィールドの長さ指定は、1つの文字だけに適用されます
print pack("a4","abcdefg","X","Y","Z"), "\n";


# 上記の制限を回避するには、"a"フィールドを繰り返します
print pack("a" x 4, "abcdefg","X","Y","Z"), "\n";


# "a"フォーマットは、長さが足りない分をヌル文字で補います
print pack("A14","abcdefg"), "...\n";
