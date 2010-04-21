$path = "/usr/bin/perl";
$path =~ s|/usr/bin|/usr/local/bin|;
print $path, "\n";

$word = "     Let me tell ya that    ";
$word =~ s/^\s*(.*?)\s*$/$1/;	# 空白の切り詰め
print $word, ":\n";

$word = "back Looking";
$word =~ s/([^ ]*) *([^ ]*)/$2 $1/;	# 最初の2語の入れ替え
print $word, "\n";
