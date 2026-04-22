#!/bin/bash

#first arg = starting turn
#second arg = number of turns to be searched

declare -a times
declare -i timestamps=0
declare -i numOfTurns=$2-1
declare -i endingTurn=$1+($2-1)

for i in $(seq $1 ); do
    times[timestamps]=$(date +%D%t%R)
    timestamps=$timestamps+1
    ./findwins 1 $i
    times[timestamps]=$(date +%D%t%R)
    timestamps=$timestamps+1
done

timestamps=0

for i in $(seq 0 $numOfTurns); do
    echo "Start: ${times[$timestamps]}"
    timestamps=$timestamps+1
done