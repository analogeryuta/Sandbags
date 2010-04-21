#!/usr/local/bin/perl -w

use strict;

my %mgs_1 = ("Revolver","Ocelot","Psyco","Mantis","Solid","Snake");

my %mgs_2 = ("Liquid","Solidus","Snake","Otacon","Jack","Raiden");

my %mgs_3 = (
    "The Joy" => "The Boss",
    "Naked Snake" => "Big Boss",
    "Ocelot" => "Revolver Ocelot",
    "FOX" => "FOX HOUND"
);

print $mgs_1{"Revolver"} . " \n";
print $mgs_2{"Jack"} . "\n";
print $mgs_3{"The Joy"} . "\n";


my @code_name = keys(%mgs_1);
print "@code_name \n";

my @code_name2 = values(%mgs_1);
print "@code_name2 \n";

my @code_name3 = values(%mgs_3);

my $cnt=0;
foreach(@code_name3) {
    print "$code_name3[$cnt] \n";
    $cnt++;
}

while (($key, $val) = each(%mgs_2)) {
	print "key : $key,  values : $val \n";
}

@words = qw(Suns Of Liberty);
