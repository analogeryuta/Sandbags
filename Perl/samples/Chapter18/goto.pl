# 実用性のないスクリプトですが、gotoの動作がわかると思います
$max_number = 1;
LOOP1:while(1){
    for (1 .. $max_number) {
        print "LOOP1:", $max_number, "\n";
    }
    goto LOOP2;
}
LOOP2:{
    print "LOOP2:", $max_number, "\n";
}
