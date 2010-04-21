#!/usr/local/bin/perl

print "Content-type: text/html", "\n\n";

# アクセス許可するドメインを設定
my $host_address = 'domain\.com';

# 指定したドメインと環境変数REMOTE_HOSTの値を比べる
if ( $ENV{'REMOTE_HOST'} =~ /^\.$host_address$/ ){
    # アクセス成功
    print "Success in login\n";
} else {
    # アクセス失敗
    print "Failure of login\n";
}
