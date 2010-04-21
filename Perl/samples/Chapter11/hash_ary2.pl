#!/usr/bin/perl

%hash = (
    element1 => [ 1, 2 ],
    element2 => [ 3, 4 ],
    element3 => [ 5, 6 ],
);

print $hash{"element1"}[0];
