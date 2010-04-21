#!/usr/local/bin/perl

# 1.�Ķ��ѿ�REQUEST_METHOD������å����ƥꥯ�����ȥ᥽�åɡ�GET�ޤ���POST�ˤ�Ƚ�Ǥ��롣
if( $ENV{'REQUEST_METHOD'} eq "GET" ) {
# 2.GET�Ǥ���С��Ķ��ѿ�QUERY_STRING���饯������ɤ߹��ࡣ
    $buffer = $ENV{'QUERY_STRING'};
} else {
# 3.POST�Ǥ���С��Ķ��ѿ�CONTENT_LENGTH����Ѥ��ƥꥯ�����ȤΥ�������Ĵ�١�ɸ�����Ϥ��饯������ɤ߹��ࡣ
    read( STDIN, $buffer, $ENV{'CONTENT_LENGTH'} );
}

print "Content-Type: text/html", "\n\n";

print "<b>Data</b> ", $buffer, "<br>\n";
print "<b>Split Data</b><br> ", "\n";

# 4.������򥯥��������� ? �ˤ�ʬ�䤹�롣
my @pairs = split(/&/,$buffer);
foreach $pair (@pairs){
# 5.�������ͤ�ʬ�䤹���key=value&key=value...�ˡ�
    my($name, $value) = split(/=/, $pair);
# 6.���ڡ����� �ˤ�ץ饹��+�ˤ��Ѵ����롣
    $value =~ tr/+/ /;
# 7.16�ʿ��˥��󥳡��ɤ��줿ʸ�����ǥ����ɤ��롣
    $value =~ s/%([a-fA-F0-9][a-fA-F0-9])/pack("C", hex($1))/eg;
    print "$name : $value<br>";
}
