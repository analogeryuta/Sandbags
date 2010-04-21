#!/usr/local/bin/perl -w


for(my $cnt=0; $cnt<10; $cnt++) {
    print $cnt;
    if ($cnt eq 9) {
	print "\n";
    }
}

my $cnt2=10;
while ($cnt2 > 0) {
    print $cnt2 . " ";
    $cnt2--;
    if ($cnt2 == 0) {print "end \n";}
}

@my_name = qw(My name is Yuta Akamine);
my $cnt3=0;
foreach (@my_name) {
    print $my_name[$cnt3]." ";
    $cnt3++;
    //$cnt3 と 配列my_nameの要素数が一致したら改行
    if ($cnt3 eq @my_name) {print "\n"};
}
