#!/usr/local/bin/perl

print "Content-type: text/html", "\n\n";

my $agent = $ENV{'HTTP_USER_AGENT'};
# HTTP_USER_AGENT���ͤ����
print $agent,"<br>\n";

if ( $agent =~ /^Mozilla/ ){
    # �������ץ���ξ��
    if ( $agent =~ /^Mozilla\/[0-9\.]+\s\(compatible\; MSIE/ ){
        print "IE<br>\n";
    # �ͥåȥ������פξ��
    } else {
        print "NN<br>\n";
    }
# ����¾�Υ֥饦���ξ��
} else {
        print "OTHER<br>\n";
}
