#!/usr/bin/perl -w

use strict;
use threads;

my @threads;

print "Create threads\n";
foreach (1 .. 5){
	my $thread = threads->new(\&my_thread, $_);
	push(@threads, $thread);
}

print "Join threads \n";
foreach(@threads){
	my ($return) = $_->join;
	print "$return closed\n";
}

# スレッド処理
sub my_thread {
	my $i = shift;
	foreach (1 .. 3){
	    print "Thread $i($_)\n";
	    threads->yield();
	    sleep 1;
	}
	return ($i);
}
