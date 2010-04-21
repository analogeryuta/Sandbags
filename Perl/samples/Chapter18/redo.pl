# 実用性のないスクリプトですが、redoの動作がわかると思います
# redoは条件を再評価せず実行するので、
# $iがマイナスになるまで出力されます
$i = 5;
LOOP1:while($i) {
    $i--;
    print "LOOP1:", $i, "\n";
    print "exit\n", exit if $i < 0;	# この行がないと永遠に続く
    redo LOOP1 if $i == 0;
}