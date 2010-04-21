#!/usr/bin/perl -w
use strict;


$port = GetPort();
SetPort($port);
$desc = AECreateDesc("TEXT", "Hello, World") or die $^E;
