#!/bin/bash

> test/results.log

declare -a arr=("scenario1.json" "scenario2.json")

for i in "${arr[@]}"
do
    ./a.out "$i" >> test/results.log
done

if [ "$(diff "test/results.log" "test/check.txt")" == "" ]; then
    echo "Everything is okay"
    exit 0
else
    echo "Something went wrong :("
    exit 1
fi