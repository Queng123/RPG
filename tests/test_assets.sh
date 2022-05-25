#!/bin/bash

make

for i in $(find -type f -path "./assets/*");
    do
        mv $i "./"

        ./my_rpg & sleep 1;
        pidof -q "./my_rpg"
        return_value=$?
        if (($return_value == 0)); then
            xdotool mousemove 1908 31 click 1
        fi;

        if (($return_value == 0)); then
            printf '\033[31m0\n\033[0m'
            printf '\033[31m%s ->> not check\n\033[0m' $i
        else
            printf '\033[32m84\n\033[0m'
        fi

        path=${i%/*}
        my_array=($(echo $i | tr "/" "\n"))
        k=0
        for j in "${my_array[@]}"
            do
                k=$(($k+1))
            done
        k=$(($k-1))
        name=${my_array[$k]}
        mv $name $path
    done