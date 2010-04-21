#!/usr/bin/perl

#-------------------------------------------------#
# スーパークラスを定義
package Unix;

sub print_x { print "UNIX! \n" }

#-------------------------------------------------#
# サブクラスを定義
package Linux; 

@ISA = qw( Unix );
sub new { bless {} }
sub print_x { print "LINUX! \n" }

#-------------------------------------------------#
package main;
my $obj = new Linux;
$obj->print_x;
