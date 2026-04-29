#!/usr/local/bin/perl

$lastname="nothisone";
LINE:
while( <STDIN> ) {
	$line = $_;
	$_ =~ /^(.*),(.*),(.*),(.*)$/ ;
	$name = $1;
	next LINE if ( $1 eq $lastname );
	$lastname = $name;
	print $line;
}
