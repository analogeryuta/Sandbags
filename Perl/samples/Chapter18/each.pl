%hash = ('Akai', 27, 'Ishikawa', 30);
# ハッシュのキーと値がなくなるまで処理する
while ( ($key, $value) = each %hash ) {
    print "$key : $hash{$key}", "\n";
} 
