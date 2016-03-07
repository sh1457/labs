#!/bin/bash

tmp=""

if(($#<1))
then
	echo "No Arguments!"
else
	for i in $*
	do
		tmp=$i" "$tmp
	done

	echo "Straight :"
	echo $*

	echo "Reversed :"
	echo $tmp
fi

exit
