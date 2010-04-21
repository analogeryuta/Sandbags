%hash = ('Akai', 27, 'Ishikawa', 30);

# スカラコンテキストでは値の個数を返す
print $key = values %hash, "\n";


foreach $value ( values %hash ) {
    print $value, "\n";
}