#!/usr/local/bin/perl

# 完全なレスポンスヘッダの出力
print "Date: Mon, 01 Apr 2002 12:34:56 GMT\n";
print "Server: Apache/1.3.24 (Unix)\n";
print "Connection: close\n";
print "Content-Type: text/html", "\n\n";

# HTMLの出力
print "<HTML>\n";
print "<BODY>\n";
print "ようこそCGIの世界へ！<BR>\n";
print "</BODY>\n";
print "</HTML>\n";
