#!/usr/bin/env bash

print_red(){
    echo -e "\e[41m$@\e[49m"
}

print_blue(){
    echo -e "\e[44m$@\e[49m"
}

print_green(){
    echo -e "\e[44m$@\e[49m"
}

check_return(){
    if [ "$@" -eq "84" ]; then
        print_red "ERROR!"
    else
        print_green "OK"
    fi
}

separator(){
    echo -e "\n"
}

create_test(){
    print_blue $@
    bash -c "$@"
    check_return $?
    separator
}

create_test "./client"
create_test "./client -h"
create_test "./client -p"
create_test "./client -p 4242 -h"
create_test "./client -p abcd"
create_test "./client -h a.b.c.d"
create_test "./client -h abcd"
create_test "./client -p abcd -h a.b.c.d"
create_test "./client -p abcd -h 127.0.0.1"
create_test "./client -p 4242 -h abcd"
create_test "./client -p 4242 -h 127.0.0.1"