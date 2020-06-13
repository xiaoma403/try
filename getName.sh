#!/bin/bash
read name
NAME=$name
if [[ "$NAME" =~ ^[^a-zA-Z0-9\!@#\$%\^\&\*\(\)_+-=,./\<\>\?\;\:\"\'。、，；‘“：【】]+$ ]];then
 echo  -n $NAME
else
echo -n 2
fi
