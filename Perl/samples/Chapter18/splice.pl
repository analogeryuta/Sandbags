@list = (a, b, c, d, e, f, g);
splice( @list, 1, 2, "X", "X", "X" );

print @list, "\n";

@list = (a, b, c, d, e, f, g);
splice( @list , 1, 0, "X", "X", "X" );
print @list, "\n";

@list = (a, b, c, d, e, f, g);
splice( @list , 1, 2 );
print @list, "\n";

@list = (a, b, c, d, e, f, g);
splice( @list , -3, 2 );
print @list, "\n";

@list = (a, b, c, d, e, f, g);
splice( @list , -3);
print @list, "\n";

@list = (a, b, c, d, e, f, g);
splice( @list ,1, -3, "X");
print @list, "\n";
