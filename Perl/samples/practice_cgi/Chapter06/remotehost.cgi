#!/usr/local/bin/perl

print "Content-type: text/html", "\n\n";

# �����������Ĥ���ɥᥤ�������
my $host_address = 'domain\.com';

# ���ꤷ���ɥᥤ��ȴĶ��ѿ�REMOTE_HOST���ͤ���٤�
if ( $ENV{'REMOTE_HOST'} =~ /^\.$host_address$/ ){
    # ������������
    print "Success in login\n";
} else {
    # ������������
    print "Failure of login\n";
}
