#!/bin/bash

if [ $# -ne 2 ]
then
	echo "Incorrect Usage : Provide exactly 2 arguments!"
	exit
fi

p1=$(ls -l $1 | cut -c 2-10)
p2=$(ls -l $2 | cut -c 2-10)

if [ $p1 = $p2 ]
then
	echo "Permissions are same!"
	echo $1
	echo $2
	echo ""
	echo $p1
else
	echo "Permissions are different!"
	echo $1
	echo ""
	echo $p1
	echo $2
	echo ""
	echo $p2
fi

sleep 3

exit
