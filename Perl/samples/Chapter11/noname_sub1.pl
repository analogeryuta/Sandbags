#!/usr/bin/perl

$ref_code = sub { print "OK!\n" };
$ref_code->();

&$ref_code;
