#!/bin/bash
echo "ENTER THE NUMBER"
read n

n=${n#-}
max=0

while [ "$n" -gt 0 ]; do
    digit=$((n % 10))
    if [ "$digit" -gt "$max" ]; then
        max=$digit
    fi
    n=$((n / 10))
done

echo "THE LARGEST DIGIT OF THE NUMBER:" $max
