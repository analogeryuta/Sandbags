#!/usr/bin/perl -w
use strict;
use Tk;

my $top = MainWindow->new();
my $button = $top->Button(-text => 'Perl/Tk button 1');
$button->pack();

MainLoop();
