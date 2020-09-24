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

if [ "$(diff "test/results.log" "test/check.txt")" == "" ]; then
    echo "Everything is okay"
    exit 0
else
    echo "Something went wrong :("
    exit 1
fi