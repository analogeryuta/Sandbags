#!/usr/bin/perl -w

@array = ("one", "two", "three", "four");

@array2 = ($array[0], $array[1], $array[2], $array[3]);

@array3 = @array;

push(@array3, "five");
unshift(@array, "zero");
shift(@array2);
pop(@array);

$str = "hello, my number is ";
$str .= $array[0]; 

print "@array \n";
print "@array2 \n";
print "@array3 \n";
print $str x 3 . "\n";

