#!/bin/bash
make
clear
ITER=$2
MAX=0
MIN=-1
COUNT=1
OVER=0
COUNTOVER=0
COUNTOK=0
COUNTKO=0
COUNTERROR=0
AVG=0
TOTAL=0
while [ $COUNT -le $ITER ]; do
    ARG=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")
    RET=$(./push_swap $ARG | ./checker $ARG)
    NB=$(./push_swap $ARG | wc -l)
    TOTAL=$(expr $TOTAL + $NB)
    AVG=$(expr $TOTAL / $COUNT)
    if [ $NB -gt $MAX ]; then
        MAX=$(expr $NB)
    fi
    if [ $MIN == -1 ]; then
        MIN=$(expr $NB)
    fi
    if [ $NB -lt $MIN ]; then
        MIN=$(expr $NB)
    fi
    if [ "$RET" == "OK" ]; then
        COUNTOK=$(expr $COUNTOK + 1)
        # echo $ARG
        # read -n 1 k <&1
    elif [ "$RET" == "KO" ]; then
        COUNTKO=$(expr $COUNTKO + 1)
        # echo $RET
        # echo $ARG
        # read -n 1 k <&1
    else
        COUNTERROR=$(expr $COUNTERROR + 1)
        # echo $RET
        # echo $ARG
        # read -n 1 k <&1
    fi
    if [ $NB -gt $OVER ]; then
        COUNTOVER=$(expr $COUNTOVER + 1)
    fi
    OUTPUT="$COUNT / $ITER
current return = $RET
current op = $NB
total op = $TOTAL
OK = $COUNTOK
KO = $COUNTKO
Error = $COUNTERROR
min = $MIN
max = $MAX
over  = $COUNTOVER
avg = $AVG"
    clear
    echo -e "$OUTPUT"
    COUNT=$(expr $COUNT + 1)
done