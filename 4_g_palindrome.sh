#!/bin/bash
echo "ENTER THE STRING TO CHECK PALINDROME"
read str

reverse=$(echo "$str" | rev)

if [ "$str" = "$reverse" ]; then
    echo "$str is a palindrome"
else
    echo "$str is not a palindrome"
fi
