#!/bin/bash
read name
NAME=$name
case $NAME in
	[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]) echo -n $NAME;;
	*) echo -n N;;
esac
