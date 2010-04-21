#!/usr/bin/perl

my @list = (1..3);
my %hash = (a=>1, b=>2, c=>3);
&kansu(@list, %hash);

sub kansu{
    my(@list, %hash) = @_;

    foreach my $key( @list ){
        print "$key ";
    }
    print "\n";
    foreach my $key( keys %hash ){
        print "$key: $hash{$key} ";
    }
}
