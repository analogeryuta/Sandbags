#!/usr/bin/perl -w
use strict;
use Foundation;

my $s1 = NSString->stringWithCString_("Hello ");
my $s2 = NSString->alloc()->initWithCString_("World");
my $s3 = $s1->stringByAppendingString_($s2);
printf "%s\n", $s3->cString();
