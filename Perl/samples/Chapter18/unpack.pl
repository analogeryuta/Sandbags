$a = "It's funny how money change a situation";
 
# 5文字進んで、5文字取り出す
print unpack( "x5 A5", $a );
