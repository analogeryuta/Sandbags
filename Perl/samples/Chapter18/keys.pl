%hash = ('Akai', 27, 'Ishikawa', 30);

# スカラコンテキストではキーの個数を返す
print $key = keys %hash, "\n";


foreach $key ( keys %hash ) {
    print "$key : $hash{$key}", "\n";
}
