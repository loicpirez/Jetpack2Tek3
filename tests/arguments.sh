#!/usr/bin/env bash

print_red(){
    echo -e "\e[41m$1\e[49m"
}

print_blue(){
    echo -e "\e[44m$1\e[49m"
}

print_green(){
    echo -e "\e[44m$1\e[49m"
}

check_return(){
    if [ "$1" -eq "84" ]; then
        print_red "Fail test!"
    else
        print_green "OK"
    fi
}

separator(){
    echo -e "\e[45m                                    \e[49m"
}

create_test(){
    print_blue $1
    bash -c $1
    check_return $?
    separator
}

create_test "./client -h"