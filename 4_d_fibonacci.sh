#!/bin/bash
echo "ENTER THE LIMIT:"
read n
p=0
q=1
i=1

while [ "$i" -le "$n" ]; do
    echo "$p"
    r=$((p + q))
    p=$q
    q=$r
    i=$((i + 1))
done
