# ▼パスワードの自動生成
my ($result,$intval)=('','');
srand(time);
while ( length($result) <= 8 ){
    # ASCII英数字の文字コードを生成(48から122)
    $intval = int( rand(75) ) + 48;
    # 文字コード91から96、58から64は英数字以外の文字
    # なので、文字コードの生成処理をやり直す
    next if ($intval >= 91 and $intval <= 96 ) 
        or ($intval >= 58 and $intval <= 64);
    $result .= sprintf("%c", $intval);
}
print $result, "\n";
