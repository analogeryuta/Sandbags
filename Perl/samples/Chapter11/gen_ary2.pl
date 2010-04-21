#!/usr/bin/perl

@list = (
    [ "LUCY", "LIU" ],
    [ "CAMERON", "DIAZ" ],
    [ "DREW", "BARRYMORE", "produced by drew" ],
);

print $list[0][0], " & ", $list[1][0], " & ", $list[2][0], "\n";

print $list[2][2], "\n";
