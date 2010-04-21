$word = "one two tree";
while( $word =~ /o/g ){
    print pos $word, " ";
}