#!/bin/bash

touch test/results.log

declare -a arr=("kakarott.json" "vakarott.json" "makarott.json")

for i in "${arr[@]}"
do
    for j in "${arr[@]}"
    do
        if [[ "$i" != "$j" ]]
        then
            echo "$i" "$j"
            ./a.out "$i" "$j" >> test/results.log
        fi
    done
done

if cmp -s "test/results.log" "test/check.txt"; then
    echo "Everything is okay"
else
    echo "Something went wrong :("
fi