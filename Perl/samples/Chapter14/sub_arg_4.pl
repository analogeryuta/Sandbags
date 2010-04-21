#!/usr/bin/perl

my @list = (1..3);
my %hash = (a=>1, b=>2, c=>3);
&kansu( \@list, \%hash );

sub kansu{
    my ($list, $hash) = @_;

    print "-------list--------", "\n";
    foreach my $key( @{ $list } ){
        print "$key", "\n";
    }
    print "-------hash--------", "\n";
    foreach my $key( keys % { $hash } ){
        print "$key: $hash->{$key}", "\n";
    }
}
