#!/bin/bash
echo "ENTER THE VALUE OF A:"
read a
echo "ENTER THE VALUE OF B:"
read b

echo "1.ADDITION 2.SUBTRACTION 3.MULTIPLICATION 4.DIVISION"
read op

case "$op" in
    1) echo $((a + b)) ;;
    2) echo $((a - b)) ;;
    3) echo $((a * b)) ;;
    4)
        if [ "$b" -eq 0 ]; then
            echo "DIVISION BY ZERO NOT ALLOWED"
        else
            echo $((a / b))
        fi
        ;;
    *) echo "INVALID OPTION" ;;
esac
