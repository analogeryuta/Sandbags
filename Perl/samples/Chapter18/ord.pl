$word = 'rhythm';

# 最初の文字を符号なしASCII値を返す
print ord($word), "\n";


# すべての文字を符号付きの値で返す
print unpack('C*', $word), "\n";
