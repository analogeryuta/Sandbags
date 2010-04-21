#!/usr/bin/perl

sub kansu{
    my ($val) = @_;
    return "引数は" . $val . "\n";
}

print &kansu("YES!");
