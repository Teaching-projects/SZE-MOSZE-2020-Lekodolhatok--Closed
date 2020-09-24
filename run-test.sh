#!/bin/bash

touch test/results.log

declare -a arr=("kakarott.json" "vakarott.json" "makarott.json")

for i in "${arr[@]}"
do
    for j in "${arr[@]}"
    do
        if [[ "$i" != "$j" ]]
        then
            ./a.out "$i" "$j" >> test/results.log
        fi
    done
done

cat test/results.log
echo "---"
cat test/check.txt

if cmp -s "test/results.log" "test/check.txt"; then
    echo "Everything is okay"
else
    echo "Something went wrong :("
fi