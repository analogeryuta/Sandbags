# 現在日時を取得
( $sec , $min , $hour , $day , $mon , $year ) = localtime( time );
$mon++;

printf("現在の日時：%02d月%02d日", $mon, $day );
