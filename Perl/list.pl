#!/usr/bin/perl -w

@array = ("one", "two", "three", "four");

@array2 = ($array[0], $array[1], $array[2], $array[3]);

@array3 = @array;

push(@array3, "five");
unshift(@array, "zero");

print "@array \n";
print "@array2 \n";
print "@array3 \n";


