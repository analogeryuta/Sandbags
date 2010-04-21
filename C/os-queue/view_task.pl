#!/usr/local/bin/perl

#
#    OS Scheduler Simulator
#
#** 連絡先： 琉球大学情報工学科 河野 真治  
#** （E-Mail Address: kono@ie.u-ryukyu.ac.jp）
#**
#**    このソースのいかなる複写，改変，修正も許諾します。ただし、
#**    その際には、誰が貢献したを示すこの部分を残すこと。
#**    再配布や雑誌の付録などの問い合わせも必要ありません。
#**    営利利用も上記に反しない範囲で許可します。
#**    バイナリの配布の際にはversion messageを保存することを条件とします。
#**    このプログラムについては特に何の保証もしない、悪しからず。
#**
#**    Everyone is permitted to do anything on this program 
#**    including copying, modifying, improving,
#**    as long as you don't try to pretend that you wrote it.
#**    i.e., the above copyright notice has to appear in all copies.  
#**    Binary distribution requires original version messages.
#**    You don't have to ask before copying, redistribution or publishing.
#**    THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE.
#
# Gantt Chart Generator
#

use strict;

use Tk;
use Getopt::Std;
getopts('t'); 

use vars qw($opt_t);

my @color=("blue","green","yellow","gray","pink","violet","black",
   "light green","light blue","dark green","white","red"
);


my $m = MainWindow->new;
my $w_quit = $m->Button(-text => 'Quit', -width => 8, -command => ['destroy', $m]);
$w_quit->pack;
my $c = $m->Canvas; $c->pack;

my $last;
my %task;
my $scale = 3;
my @data;

while(<>) {
    if (/^(\d+)\s+([^\s]*):\s+(.*)/) {
	push(@data,[$1,$2,$3]);
	$task{$2} = 1;
    }
}
my ($last) = pop(@data);

$c->configure(-width=>$last+10);

my $y = 10;
my $x = 20;
my $delta = 0;
my $color = 0;
my %color;
my %pos;

for(keys %task) {
    next if (/end/);
    $color{$_} = $color[$color++];
    if ($opt_t) {
	$pos{$_} = $y + $delta;
	$c->create('text',5,$y+$delta+10,-text=>$_);
	$delta += 20;
    } else {
	$pos{$_} = $y;
    }
}

for(@data) {
    my($time,$name,$length) = @$_;
    my $ny = $pos{$name};
    if ($length =~ /miss/) {
	next;
    }
    $time *= $scale;
    $length *= $scale;
    my $rect =
       $c->create('rectangle',
          $time+$x,$ny,$time+$x+$length,$ny+20,-fill=>$color{$name});
    if (! $opt_t) {
	$c->create('text',$time+$x+10,$ny+10,-text=>$name,-fill=>'black');
    }
}

for(@data) {
    my($time,$name,$length) = @$_;
    my $ny = $pos{$name};
    $time *= $scale;
    if ($length =~ /miss/) {
	$c->create('text',$time+$x+10,$ny+10,-text=>'*',-fill=>'red');
    }
}

$m->MainLoop;

# end
