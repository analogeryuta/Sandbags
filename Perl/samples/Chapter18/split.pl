$var = "One:Two:Three";
@list = split( /:/ , $var );	# @listの内容は(One, Two, Three)
print @list, "\n";

# LIMITを使う
$var = "One:Two:Three";
@list = split( /:/ , $var, 2 );	# @listの内容は(One, Two:Three)
print @list, "\n";
