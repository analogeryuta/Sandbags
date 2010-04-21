# 暗号化したい文字列($val)を受け取り、暗号化した文字列を返す関数
sub cipher {
    my ($val) = @_;

    my( $sec, $min, $hour, $day, $mon, $year, $weekday ) 
        = localtime( time );
    my( @token ) = ( '0'..'9', 'A'..'Z', 'a'..'z' );
    my $salt1 = $token[(time | $$) % scalar(@token)];
    my $salt2 = $token[($sec + $min*60 + $hour*60*60) % scalar(@token)];
    return crypt( $val, $salt1.$salt2 );
}

# パスワード($passwd1)と暗号化したパスワード($passwd2)を受け取り、
# 一致するかを判定する関数
sub decipher{
    my ($passwd1, $passwd2) = @_;

    # 暗号のチェック
    if ( crypt($passwd1, $passwd2) eq $passwd2 ) {
        return 1;
    } else {
        return 0;
    }
}
