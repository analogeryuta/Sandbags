#!/usr/local/bin/perl

print "Content-type: text/html", "\n\n";

my $agent = $ENV{'HTTP_USER_AGENT'};
# HTTP_USER_AGENTの値を出力
print $agent,"<br>\n";

if ( $agent =~ /^Mozilla/ ){
    # エクスプローラの場合
    if ( $agent =~ /^Mozilla\/[0-9\.]+\s\(compatible\; MSIE/ ){
        print "IE<br>\n";
    # ネットスケープの場合
    } else {
        print "NN<br>\n";
    }
# その他のブラウザの場合
} else {
        print "OTHER<br>\n";
}
