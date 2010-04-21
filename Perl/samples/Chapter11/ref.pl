#!/usr/bin/perl

$ref_a = \1;
print ref $ref_a, "\n";

$ref_b = sub{'code'};
print ref $ref_b, "\n";
