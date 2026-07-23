#!/bin/bash

#first arg = starting turn
#second arg = number of turns to be searched

declare -a times
declare -i timestamps=0
declare -i numOfTurns=$(($2-1))
declare -i Turn

for i in $(seq 0 $numOfTurns); do
    if [[ $i%2 != 0 ]]; then
         Turn=$1+$(($i*2))
    fi

    times[timestamps]=$(date +%D%t%R)
    timestamps=$timestamps+1
    ./findwins $Turn
    times[timestamps]=$(date +%D%t%R)
    timestamps=$timestamps+1

    echo "Start: ${times[$(($timestamps-2))]} End: ${times[$(($timestamps-1))]}" >> Output.txt
done

timestamps=0

for i in $(seq 0 $numOfTurns); do
    if [[ $i%2 != 0 ]]; then
         Turn=$1+$(($i*2))
    fi

    echo "Turn: $Turn Start: ${times[$timestamps]} End: ${times[$timestamps+1]}"
    timestamps=$timestamps+2
done 